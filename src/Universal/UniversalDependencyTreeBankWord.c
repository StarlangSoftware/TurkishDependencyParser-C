//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#include <StringUtils.h>
#include <Memory/Memory.h>
#include "UniversalDependencyTreeBankWord.h"

/**
 * Constructor of the universal dependency word. Sets the attributes.
 * @param id Id of the word
 * @param name Name of the word
 * @param lemma Lemma of the word
 * @param upos Universal part of speech tag.
 * @param xpos Extra part of speech tag
 * @param features Feature list of the word
 * @param relation Universal dependency relation of the word
 * @param deps External dependencies for the word
 * @param misc Miscellaneous information for the word.
 */
Universal_dependency_tree_bank_word_ptr
create_universal_dependency_tree_bank_word(int id,
                                           const char *name,
                                           const char *lemma,
                                           Universal_dependency_pos_type upos,
                                           const char *xpos,
                                           Universal_dependency_tree_bank_features_ptr features,
                                           Universal_dependency_relation_ptr relation,
                                           const char *deps,
                                           const char *misc) {
    Universal_dependency_tree_bank_word_ptr result = malloc_(sizeof(Universal_dependency_tree_bank_word));
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

/**
 * Default constructor for the universal dependency word. Sets the attributes to default values.
 */
Universal_dependency_tree_bank_word_ptr create_universal_dependency_tree_bank_word2() {
    Universal_dependency_tree_bank_word_ptr result = malloc_(sizeof(Universal_dependency_tree_bank_word));
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

/**
 * Frees memory allocated for dependency word. Deallocates features hash map, dependency relation, and name, lemma, xpos
 * deps and misc strings.
 * @param universal_dependency_tree_bank_word Word to be deallocated.
 */
void
free_universal_dependency_tree_bank_word(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word) {
    free_universal_dependency_relation(universal_dependency_tree_bank_word->relation);
    if (universal_dependency_tree_bank_word->features != NULL){
        free_universal_dependency_tree_bank_features(universal_dependency_tree_bank_word->features);
    }
    free_(universal_dependency_tree_bank_word->name);
    free_(universal_dependency_tree_bank_word->lemma);
    free_(universal_dependency_tree_bank_word->xpos);
    free_(universal_dependency_tree_bank_word->deps);
    free_(universal_dependency_tree_bank_word->misc);
    free_(universal_dependency_tree_bank_word);
}

/**
 * Gets the value of a given feature.
 * @param universal_dependency_tree_bank_word Current word to be processed
 * @param feature_name Name of the feature
 * @return Value of the feature
 */
char *
get_feature_value2(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word, const char *feature_name) {
    return get_feature_value(universal_dependency_tree_bank_word->features, feature_name);
}

/**
 * Checks if the given feature exists.
 * @param universal_dependency_tree_bank_word Current word to be processed
 * @param feature_name Name of the feature
 * @return True if the given feature exists, false otherwise.
 */
bool feature_exists2(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word, const char *feature_name) {
    return feature_exists(universal_dependency_tree_bank_word->features, feature_name);
}

Universal_dependency_tree_bank_word_ptr
clone_universal_dependency_tree_bank_word(Universal_dependency_tree_bank_word_ptr universal_dependency_tree_bank_word) {
    Universal_dependency_tree_bank_word_ptr result = malloc_(sizeof(Universal_dependency_tree_bank_word));
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
