//
// Created by Olcay Taner YILDIZ on 14.11.2023.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H

#include <ArrayList.h>
#include "../ParserEvaluationScore.h"

struct universal_dependency_tree_bank_sentence{
    Array_list_ptr words;
    Array_list_ptr comments;
    Array_list_ptr splits;
};

typedef struct universal_dependency_tree_bank_sentence Universal_dependency_tree_bank_sentence;

typedef Universal_dependency_tree_bank_sentence *Universal_dependency_tree_bank_sentence_ptr;

Universal_dependency_tree_bank_sentence_ptr create_universal_dependency_tree_bank_sentence(const char* language, const char* sentence);

void free_universal_dependency_tree_bank_sentence(Universal_dependency_tree_bank_sentence_ptr sentence);

Parser_evaluation_score_ptr compare_sentences(Universal_dependency_tree_bank_sentence_ptr sentence1, Universal_dependency_tree_bank_sentence_ptr sentence2);

int split_size_universal_dependency_tree_bank_sentence(Universal_dependency_tree_bank_sentence_ptr sentence);

char* get_split_universal_dependency_tree_bank_sentence(Universal_dependency_tree_bank_sentence_ptr sentence, int index);

#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H
