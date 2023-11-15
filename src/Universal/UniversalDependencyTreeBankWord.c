//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include "UniversalDependencyTreeBankWord.h"

Universal_dependency_tree_bank_word_ptr
create_universal_dependency_tree_bank_word(int id,
                                           char *name,
                                           char *lemma,
                                           Universal_dependency_pos_type upos,
                                           char *xpos,
                                           Universal_dependency_tree_bank_features_ptr features,
                                           Universal_dependency_relation_ptr relation,
                                           char *deps,
                                           char *misc) {
    Universal_dependency_tree_bank_word_ptr result = malloc(sizeof(Universal_dependency_tree_bank_word));
    result->id = id;
    result->name = str_copy(result->name, name);
    result->lemma = str_copy(result->lemma, lemma);
    result->upos = upos;
    result->xpos = str_copy(result->xpos, xpos);
    result->features = features;
    result->relation = relation;
    result->deps = str_copy(result->deps, deps);
    result->misc = str_copy(result->misc, misc);
    return result;
}

Universal_dependency_tree_bank_word_ptr create_universal_dependency_tree_bank_word2() {
    Universal_dependency_tree_bank_word_ptr result = malloc(sizeof(Universal_dependency_tree_bank_word));
    result->id = 0;
    result->name = NULL;
    result->lemma = NULL;
    result->upos = X;
    result->xpos = NULL;
    result->features = NULL;
    result->relation = create_universal_dependency_relation(-1, "DEP");
    result->deps = NULL;
    result->misc = NULL;
    return result;
}

void
free_universal_dependency_tree_bank_word(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word) {
    free_universal_dependency_relation(universal_dependency_tree_bank_word->relation);
    if (universal_dependency_tree_bank_word->features != NULL){
        free_universal_dependency_tree_bank_features(universal_dependency_tree_bank_word->features);
    }
    free(universal_dependency_tree_bank_word->name);
    free(universal_dependency_tree_bank_word->lemma);
    free(universal_dependency_tree_bank_word->xpos);
    free(universal_dependency_tree_bank_word->deps);
    free(universal_dependency_tree_bank_word->misc);
    free(universal_dependency_tree_bank_word);
}

char *
get_feature_value2(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word, char *feature_name) {
    return get_feature_value(universal_dependency_tree_bank_word->features, feature_name);
}

bool feature_exists2(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word, char *feature_name) {
    return feature_exists(universal_dependency_tree_bank_word->features, feature_name);
}

Universal_dependency_tree_bank_word_ptr
clone_universal_dependency_tree_bank_word(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word) {
    Universal_dependency_tree_bank_word_ptr result = malloc(sizeof(Universal_dependency_tree_bank_word));
    result->id = universal_dependency_tree_bank_word->id;
    result->name = str_copy(result->name, universal_dependency_tree_bank_word->name);
    result->lemma = str_copy(result->lemma, universal_dependency_tree_bank_word->lemma);
    result->upos = universal_dependency_tree_bank_word->upos;
    result->xpos = str_copy(result->xpos, universal_dependency_tree_bank_word->xpos);
    result->features = clone_universal_dependency_tree_bank_features(universal_dependency_tree_bank_word->features);
    result->relation = clone_universal_dependency_relation(universal_dependency_tree_bank_word->relation);
    result->deps = str_copy(result->deps, universal_dependency_tree_bank_word->deps);
    result->misc = str_copy(result->misc, universal_dependency_tree_bank_word->misc);
    return result;
}
