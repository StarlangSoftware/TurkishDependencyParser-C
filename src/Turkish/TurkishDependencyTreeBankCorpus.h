//
// Created by Olcay Taner YILDIZ on 13.11.2023.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKCORPUS_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKCORPUS_H

#include <Corpus.h>

Corpus_ptr create_turkish_dependency_tree_bank_corpus(const char* file_name);

void free_turkish_dependency_tree_bank_corpus(Corpus_ptr corpus);

#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKCORPUS_H
