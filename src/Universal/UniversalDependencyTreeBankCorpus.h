//
// Created by Olcay Taner YILDIZ on 14.11.2023.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H

#include <ArrayList.h>
#include "../ParserEvaluationScore.h"

struct universal_dependency_tree_bank_corpus{
    Array_list_ptr sentences;
    char* language;
};

typedef struct universal_dependency_tree_bank_corpus Universal_dependency_tree_bank_corpus;

typedef Universal_dependency_tree_bank_corpus *Universal_dependency_tree_bank_corpus_ptr;

Universal_dependency_tree_bank_corpus_ptr create_universal_dependency_tree_bank_corpus(const char* file_name);

Parser_evaluation_score_ptr compare_parses(Universal_dependency_tree_bank_corpus_ptr corpus1, Universal_dependency_tree_bank_corpus_ptr corpus2);

void free_universal_dependency_tree_bank_corpus(Universal_dependency_tree_bank_corpus_ptr corpus);

#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H
