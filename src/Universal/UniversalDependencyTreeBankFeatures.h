//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H

#include <HashMap/HashMap.h>
#include "UniversalDependencyPosType.h"

struct universal_dependency_tree_bank_features{
    Hash_map_ptr feature_list;
};

typedef struct universal_dependency_tree_bank_features Universal_dependency_tree_bank_features;

typedef Universal_dependency_tree_bank_features *Universal_dependency_tree_bank_features_ptr;

Universal_dependency_tree_bank_features_ptr create_universal_dependency_tree_bank_features(const char* features);

void free_universal_dependency_tree_bank_features(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features);

char* get_feature_value(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features, char* feature);

bool feature_exists(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features, char* feature);

int feature_index(char* feature_name);

int dependency_index(char* universal_dependency);

int number_of_values(char* language, char* feature_name);

int feature_value_index(char* language, char* feature_name, char* feature_value);

int pos_index(char* u_pos);

char* get_pos_string(Universal_dependency_pos_type u_pos);

char* universal_dependency_tree_bank_features_to_string(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features);

Universal_dependency_tree_bank_features_ptr clone_universal_dependency_tree_bank_features(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features);

void add_to_feature_list(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features, const char* features);

#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
