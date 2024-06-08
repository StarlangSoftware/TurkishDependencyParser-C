//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#include <StringUtils.h>
#include <string.h>
#include <Memory/Memory.h>
#include "UniversalDependencyRelation.h"
#include "UniversalDependencyPosType.h"

/**
 * Another constructor for UniversalDependencyRelation. Gets input toWord and dependencyType as arguments and
 * calls the super class's constructor and sets the dependency type.
 * @param toWord Index of the word in the sentence that dependency relation is related
 * @param dependencyType Type of the dependency relation in string form
 */
Universal_dependency_relation_ptr
create_universal_dependency_relation(int to_word, const char* dependency_type) {
    Universal_dependency_relation_ptr result = malloc_(sizeof(Universal_dependency_relation), "create_universal_dependency_relation");
    result->to_word = to_word;
    result->universal_dependency_type = get_universal_dependency_tag(dependency_type);
    return result;
}

/**
 * Overridden Universal Dependency Relation constructor. Gets toWord as input and calls it super class's constructor
 * @param toWord Index of the word in the sentence that dependency relation is related
 */
Universal_dependency_relation_ptr create_universal_dependency_relation2(int to_word) {
    Universal_dependency_relation_ptr result = malloc_(sizeof(Universal_dependency_relation), "create_universal_dependency_relation2");
    result->to_word = to_word;
    return result;
}

/**
 * The getDependencyTag method takes an dependency tag as string and returns the UniversalDependencyType
 * form of it.
 *
 * @param tag  Type of the dependency tag in string form
 * @return Type of the dependency in UniversalDependencyType form
 */
Universal_dependency_type get_universal_dependency_tag(const char *tag) {
    char* _tag = lowercase_en(tag);
    int index = string_index(_tag, universal_dependency_types, 62);
    free_(_tag);
    if (index != -1){
        return universal_dependency_tags[index];
    }
    return DEP;
}

Universal_dependency_pos_type get_universal_dependency_pos_tag(const char *tag) {
    char* _tag = uppercase_en(tag);
    int index = string_index(_tag, universal_dependency_pos_types, 17);
    free_(_tag);
    if (index != -1){
        return universal_dependency_pos_tags[index];
    }
    return X;
}

/**
 * Compares the relation with the given universal dependency relation and returns a parser evaluation score for this
 * comparison. If toWord fields are equal for both relation UAS is 1, otherwise it is 0. If both toWord and
 * dependency types are the same, LAS is 1, otherwise it is 0. If only dependency types of both relations are
 * the same, LS is 1, otherwise it is 0.
 * @param relation Universal dependency relation to be compared.
 * @return A parser evaluation score object with (i) LAS = 1, if to and dependency types are same; LAS = 0,
 * otherwise, (ii) UAS = 1, if to is the same; UAS = 0, otherwise, (iii) LS = 1, if dependency types are the same;
 * LS = 0, otherwise.
 */
Parser_evaluation_score_ptr
compare_relations(Universal_dependency_relation_ptr relation1, Universal_dependency_relation_ptr relation2) {
    double LS = 0.0, LAS = 0.0, UAS = 0.0;
    if (relation1->universal_dependency_type == relation2->universal_dependency_type){
        LS = 1.0;
        if (relation1->to_word == relation2->to_word){
            LAS = 1.0;
        }
    }
    if (relation1->to_word == relation2->to_word){
        UAS = 1.0;
    }
    return create_parser_evaluation_score(LAS, UAS, LS, 1);
}

Universal_dependency_relation_ptr clone_universal_dependency_relation(Universal_dependency_relation_ptr relation) {
    Universal_dependency_relation_ptr result = malloc_(sizeof(Universal_dependency_relation), "clone_universal_dependency_relation");
    result->to_word = relation->to_word;
    result->universal_dependency_type = relation->universal_dependency_type;
    return result;
}

/**
 * Frees memory allocated fora universal dependency relation.
 * @param universal_dependency_relation Dependency relation to be deallocated.
 */
void free_universal_dependency_relation(Universal_dependency_relation_ptr universal_dependency_relation) {
    free_(universal_dependency_relation);
}

char *universal_dependency_relation_to_string(Universal_dependency_relation_ptr relation) {
    char* result = NULL;
    for (int i = 0; i < 62; i++){
        if (relation->universal_dependency_type == universal_dependency_tags[i]){
            if (relation->to_word < 10){
                result = malloc_((strlen(universal_dependency_types[i]) + 2) * sizeof(char), "universal_dependency_relation_to_string_1");
            } else {
                result = malloc_((strlen(universal_dependency_types[i]) + 3) * sizeof(char), "universal_dependency_relation_to_string_2");
            }
            break;
        }
    }
    return result;
}
