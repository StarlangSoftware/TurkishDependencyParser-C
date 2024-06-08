//
// Created by Olcay Taner YILDIZ on 14.11.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <stdio.h>
#include <Dictionary/Word.h>
#include <printf.h>
#include <string.h>
#include <RegularExpression.h>
#include <Memory/Memory.h>
#include "UniversalDependencyTreeBankSentence.h"
#include "UniversalDependencyPosType.h"
#include "UniversalDependencyRelation.h"
#include "UniversalDependencyTreeBankFeatures.h"
#include "UniversalDependencyTreeBankWord.h"

/**
 * Constructor for the UniversalDependencyTreeBankSentence.  Get a line as input and splits the line wrt tab
 * character. The number of items should be 10. The items are id, surfaceForm, lemma, upos, xpos, feature list,
 * head word index, dependency type, external dependencies and miscellaneous things for one word.
 * @param language Language name. Currently, 'en' and 'tr' languages are supported.
 * @param sentence Sentence string to be processed.
 */
Universal_dependency_tree_bank_sentence_ptr
create_universal_dependency_tree_bank_sentence(const char* language, const char *sentence) {
    Universal_dependency_tree_bank_sentence_ptr result = malloc_(sizeof(Universal_dependency_tree_bank_sentence), "create_universal_dependency_tree_bank_sentence");
    result->words = create_array_list();
    result->comments = create_array_list();
    Array_list_ptr lines = str_split(sentence, '\n');
    Regular_expression_ptr expression = create_regular_expression("\\d+");
    for (int i = 0; i < lines->size; i++){
        char* line = array_list_get(lines, i);
        if (strlen(line) == 0){
            continue;
        }
        if (starts_with(line, "#")){
            array_list_add(result->comments, clone_string(line));
        } else {
            Array_list_ptr items = str_split(line, '\t');
            if (items->size != 10){
                printf("Line does not contain 10 items -> %s", line);
            } else {
                char* id = array_list_get(items, 0);
                if (full_matches(expression, id)){
                    char* surface_form = array_list_get(items, 1);
                    char* lemma = array_list_get(items, 2);
                    Universal_dependency_pos_type upos = get_universal_dependency_pos_tag(array_list_get(items, 3));
                    char* xpos = array_list_get(items, 4);
                    Universal_dependency_tree_bank_features_ptr features = create_universal_dependency_tree_bank_features(array_list_get(items, 5));
                    Universal_dependency_relation_ptr relation = NULL;
                    if (strcmp(array_list_get(items, 6), "_") != 0){
                        int to = atoi(array_list_get(items, 6));
                        char* tmp = array_list_get(items, 7);
                        char* dependency_type = uppercase_en(tmp);
                        relation = create_universal_dependency_relation(to, dependency_type);
                        free_(dependency_type);
                    }
                    char* deps = array_list_get(items, 8);
                    char* misc = array_list_get(items, 9);
                    Universal_dependency_tree_bank_word_ptr word = create_universal_dependency_tree_bank_word(atoi(id), surface_form, lemma, upos, xpos, features, relation, deps, misc);
                    array_list_add(result->words, word);
                }
            }
            free_array_list(items, free_);
        }
    }
    free_regular_expression(expression);
    free_array_list(lines, free_);
    return result;
}

/**
 * Frees memory allocated for dependency sentence. Deallocates words and comments array lists.
 * @param sentence Sentence to be deallocated.
 */
void free_universal_dependency_tree_bank_sentence(Universal_dependency_tree_bank_sentence_ptr sentence) {
    free_array_list(sentence->words, (void (*)(void *)) free_universal_dependency_tree_bank_word);
    free_array_list(sentence->comments, free_);
    free_(sentence);
}

/**
 * Compares the sentence with the given sentence and returns a parser evaluation score for this comparison. The result
 * is calculated by summing up the parser evaluation scores of word by word dpendency relation comparisons.
 * @param sentence Universal dependency sentence to be compared.
 * @return A parser evaluation score object.
 */
Parser_evaluation_score_ptr compare_sentences(Universal_dependency_tree_bank_sentence_ptr sentence1,
                                              Universal_dependency_tree_bank_sentence_ptr sentence2) {
    Parser_evaluation_score_ptr score = create_parser_evaluation_score2();
    for (int i = 0; i < sentence1->words->size; i++){
        Universal_dependency_relation_ptr relation1 = ((Universal_dependency_tree_bank_word_ptr) array_list_get(sentence1->words, i))->relation;
        Universal_dependency_relation_ptr relation2 = ((Universal_dependency_tree_bank_word_ptr) array_list_get(sentence2->words, i))->relation;
        if (relation1 != NULL && relation2 != NULL){
            add_score(score, compare_relations(relation1, relation2));
        }
    }
    return score;
}
