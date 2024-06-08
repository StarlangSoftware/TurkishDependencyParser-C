//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "TurkishDependencyTreeBankWord.h"
#include "Memory/Memory.h"

/**
 * Given the parsed xml node which contains information about a word and related attributes including the
 * dependencies, the method constructs a TurkishDependencyTreeBankWord from it.
 * @param wordNode Xml parsed node containing information about a word.
 */
Turkish_dependency_tree_bank_word_ptr create_turkish_dependency_tree_bank_word(Xml_element_ptr word_node) {
    Turkish_dependency_tree_bank_word_ptr result = malloc_(sizeof(Turkish_dependency_tree_bank_word), "create_turkish_dependency_tree_bank_word");
    char* IG, *relation_name, *dependency_type;
    int to_word = 0, to_IG = 0;
    result->original_parses = create_array_list();
    result->relation = NULL;
    if (has_attributes(word_node)){
        String_ptr st = trim(word_node->pcData);
        result->name = str_copy(result->name, st->s);
        free_string_ptr(st);
        if (get_attribute_value(word_node, "IG") != NULL){
            IG = get_attribute_value(word_node, "IG");
            Array_list_ptr inflectional_groups = split_into_inflectional_groups(IG);
            result->parse = create_morphological_parse2(inflectional_groups);
            free_array_list(inflectional_groups, free_);
        }
        if (get_attribute_value(word_node, "REL") != NULL){
            relation_name = get_attribute_value(word_node, "REL");
            if (strcmp(relation_name, "[,( )]") != 0) {
                Array_list_ptr relation_parts = str_split3(relation_name, ",[]()");
                for (int i = 0; i < relation_parts->size; i++){
                    switch (i){
                        case 0:
                            to_word = atoi(array_list_get(relation_parts, i));
                            break;
                        case 1:
                            to_IG = atoi(array_list_get(relation_parts, i));
                            break;
                        case 2:
                            dependency_type = array_list_get(relation_parts, i);
                            result->relation = create_turkish_relation(to_word - 1, to_IG - 1, dependency_type);
                            break;
                    }
                }
                free_array_list(relation_parts, free_);
            }
        }
        for (int i = 1; i <= 9; i++){
            char id[8];
            sprintf(id, "ORG_IG%d", i);
            if (get_attribute_value(word_node, id) != NULL){
                IG = get_attribute_value(word_node, id);
                Array_list_ptr inflectional_groups = split_into_inflectional_groups(IG);
                array_list_add(result->original_parses, create_morphological_parse2(inflectional_groups));
                free_array_list(inflectional_groups, free_);
            }
        }
    }
    return result;
}

/**
 * Given the morphological parse of a word, this method splits it into inflectional groups.
 * @param IG Morphological parse of the word in string form.
 * @return An array of inflectional groups stored as strings.
 */
Array_list_ptr split_into_inflectional_groups(char *IG) {
    Array_list_ptr inflectional_groups = create_array_list();
    char* ig1 = replace_all(IG, "(+Punc", "@");
    char* ig = replace_all(ig1, ")+Punc", "$");
    free_(ig1);
    Array_list_ptr iGs = str_split3(ig, "[()]");
    free_(ig);
    for (int i = 0; i < iGs->size; i++){
        char* IGI1 = replace_all(array_list_get(iGs, i), "@", "(+Punc");
        char* IGI = replace_all(IGI1, "$", ")+Punc");
        free_(IGI1);
        if (IGI != NULL){
            array_list_add(inflectional_groups, IGI);
        } else {
            free_(IGI);
        }
    }
    free_array_list(iGs, free_);
    return inflectional_groups;
}

/**
 * Accessor for a specific parse.
 * @param index Index of the word.
 * @return Parse of the index'th word
 */
Morphological_parse_ptr get_original_parse(Turkish_dependency_tree_bank_word_ptr word, int index) {
    return array_list_get(word->original_parses, index);
}

/**
 * Frees memory allocated to dependency word. Deallocates relation, morphological parse and IG array list.
 * @param word Word to be deallocated.
 */
void free_turkish_dependency_tree_bank_word(Turkish_dependency_tree_bank_word_ptr word) {
    free_(word->name);
    free_turkish_relation(word->relation);
    free_morphological_parse(word->parse);
    free_array_list(word->original_parses, (void (*)(void *)) free_morphological_parse);
    free_(word);
}
