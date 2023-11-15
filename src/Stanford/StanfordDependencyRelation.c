//
// Created by Olcay Taner YILDIZ on 9.11.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <string.h>
#include "StanfordDependencyRelation.h"

/**
 * Another constructor for StanfordDependencyRelation. Gets input toWord and dependencyType as arguments and
 * calls the super class's constructor and sets the dependency type.
 * @param toWord Index of the word in the sentence that dependency relation is related
 * @param dependencyType Type of the dependency relation in string form
 */
Stanford_dependency_relation_ptr create_stanford_relation(int to_word, const char *dependency_type) {
    Stanford_dependency_relation_ptr result = malloc(sizeof(Stanford_dependency_relation));
    result->to_word = to_word;
    result->stanford_dependency_type = get_stanford_dependency_tag(dependency_type);
    return result;
}

void free_stanford_relation(Stanford_dependency_relation_ptr stanford_relation) {
    free(stanford_relation);
}

/**
 * The getDependencyTag method takes an dependency tag as string and returns the StanfordDependencyType
 * form of it.
 *
 * @param tag  Type of the dependency tag in string form
 * @return Type of the dependency in StanfordDependencyType form
 */
Stanford_dependency_type get_stanford_dependency_tag(const char *tag) {
    char* _tag = lowercase_en(tag);
    int index = string_index(_tag, stanford_dependency_types, 49);
    free(_tag);
    if (index != -1){
        return stanford_dependency_tags[index];
    }
    return XSUBJ;
}
