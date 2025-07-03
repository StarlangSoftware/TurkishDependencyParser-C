//
// Created by Olcay Taner YILDIZ on 15.11.2023.
//

#include <Corpus.h>
#include "../src/Universal/UniversalDependencyTreeBankCorpus.h"
#include "../src/Universal/UniversalDependencyTreeBankSentence.h"

void check_corpus(Universal_dependency_tree_bank_corpus_ptr corpus, int real_sentence_count, int real_word_count, int real_split_count) {
    if (corpus->sentences->size != real_sentence_count){
        printf("Error in sentence count %d\n", corpus->sentences->size);
    }
    int word_count = 0;
    int split_count = 0;
    for (int i = 0; i < corpus->sentences->size; i++){
        Universal_dependency_tree_bank_sentence_ptr sentence = array_list_get(corpus->sentences, i);
        word_count += sentence->words->size;
        split_count += sentence->splits->size;
    }
    if (word_count != real_word_count){
        printf("Error in word count %d\n", word_count);
    }
    if (split_count != real_split_count){
        printf("Error in split count %d\n", split_count);
    }
}

int main(){
    Universal_dependency_tree_bank_corpus_ptr corpus = create_universal_dependency_tree_bank_corpus("tr_gb-ud-test.conllu");
    check_corpus(corpus, 2880, 17177, 371);
    free_universal_dependency_tree_bank_corpus(corpus);
    corpus = create_universal_dependency_tree_bank_corpus("tr_imst-ud-dev.conllu");
    check_corpus(corpus, 1100, 10542, 279);
    free_universal_dependency_tree_bank_corpus(corpus);
    corpus = create_universal_dependency_tree_bank_corpus("tr_imst-ud-test.conllu");
    check_corpus(corpus, 1100, 10032, 278);
    free_universal_dependency_tree_bank_corpus(corpus);
    corpus = create_universal_dependency_tree_bank_corpus("tr_imst-ud-train.conllu");
    check_corpus(corpus, 3435, 37522, 1082);
    free_universal_dependency_tree_bank_corpus(corpus);
    corpus = create_universal_dependency_tree_bank_corpus("tr_pud-ud-test.conllu");
    check_corpus(corpus, 1000, 16881, 346);
    free_universal_dependency_tree_bank_corpus(corpus);
    corpus = create_universal_dependency_tree_bank_corpus("tr_boun-ud-dev.conllu");
    check_corpus(corpus, 979, 12289, 266);
    free_universal_dependency_tree_bank_corpus(corpus);
    corpus = create_universal_dependency_tree_bank_corpus("tr_boun-ud-test.conllu");
    check_corpus(corpus, 979, 12210, 194);
    free_universal_dependency_tree_bank_corpus(corpus);
    corpus = create_universal_dependency_tree_bank_corpus("tr_boun-ud-train.conllu");
    check_corpus(corpus, 7803, 100713, 2914);
    free_universal_dependency_tree_bank_corpus(corpus);
}