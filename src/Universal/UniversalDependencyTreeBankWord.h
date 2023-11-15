//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H

#include "UniversalDependencyPosType.h"
#include "UniversalDependencyTreeBankFeatures.h"
#include "UniversalDependencyRelation.h"

struct universal_dependency_tree_bank_word{
    char* name;
    int id;
    char* lemma;
    Universal_dependency_pos_type upos;
    char* xpos;
    Universal_dependency_tree_bank_features_ptr features;
    Universal_dependency_relation_ptr relation;
    char* deps;
    char* misc;
};

typedef struct universal_dependency_tree_bank_word Universal_dependency_tree_bank_word;

typedef Universal_dependency_tree_bank_word *Universal_dependency_tree_bank_word_ptr;

Universal_dependency_tree_bank_word_ptr create_universal_dependency_tree_bank_word(int id,
                                                                                   char* name,
                                                                                   char* lemma,
                                                                                   Universal_dependency_pos_type upos,
                                                                                   char* xpos,
                                                                                   Universal_dependency_tree_bank_features_ptr features,
                                                                                   Universal_dependency_relation_ptr relation,
                                                                                   char* deps,
                                                                                   char* misc);

void free_universal_dependency_tree_bank_word(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word);

char* get_feature_value2(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word, char* feature_name);

bool feature_exists2(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word, char* feature_name);

Universal_dependency_tree_bank_word_ptr create_universal_dependency_tree_bank_word2();

Universal_dependency_tree_bank_word_ptr clone_universal_dependency_tree_bank_word(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word);

#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKWORD_H
