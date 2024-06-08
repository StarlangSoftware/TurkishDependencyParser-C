//
// Created by Olcay Taner YILDIZ on 9.11.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <Memory/Memory.h>
#include "TurkishDependencyRelation.h"

/**
 * Another constructor for TurkishDependencyRelation. Gets input toWord, toIG, and dependencyType as arguments and
 * calls the super class's constructor and sets the IG and dependency type.
 * @param toWord Index of the word in the sentence that dependency relation is related
 * @param toIG Index of the inflectional group the dependency relation is related
 * @param dependencyType Type of the dependency relation in string form
 */
Turkish_dependency_relation_ptr create_turkish_relation(int to_word, int to_IG, const char *dependency_type) {
    Turkish_dependency_relation_ptr result = malloc_(sizeof(Turkish_dependency_relation), "create_turkish_relation");
    result->to_IG = to_IG;
    result->to_word = to_word;
    result->turkish_dependency_type = get_turkish_dependency_tag(dependency_type);
    return result;
}

/**
 * Frees memory allocated for a Turkish relation.
 * @param turkish_relation Relation to be deallocated.
 */
void free_turkish_relation(Turkish_dependency_relation_ptr turkish_relation) {
    free_(turkish_relation);
}

/**
 * The getDependencyTag method takes an dependency tag as string and returns the TurkishDependencyType
 * form of it.
 *
 * @param tag  Type of the dependency tag in string form
 * @return Type of the dependency in TurkishDependencyType form
 */
Turkish_dependency_type get_turkish_dependency_tag(const char *tag) {
    char* _tag = uppercase_en(tag);
    int index = string_index(_tag, turkish_dependency_types, 23);
    free_(_tag);
    if (index != -1){
        return turkish_dependency_tags[index];
    }
    return SENTENCE;
}
