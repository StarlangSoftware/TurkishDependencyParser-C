//
// Created by Olcay Taner YILDIZ on 15.11.2023.
//

#include <Corpus.h>
#include "../src/Universal/UniversalDependencyTreeBankCorpus.h"

int main(){
    Universal_dependency_tree_bank_corpus_ptr corpus = create_universal_dependency_tree_bank_corpus("tr_gb-ud-test.conllu");
    if (corpus->sentences->size != 2880){
        printf("Error in sentence count %d\n", corpus->sentences->size);
    }
    int word_count = 0;
    for (int i = 0; i < corpus->sentences->size; i++){
        Sentence_ptr sentence = array_list_get(corpus->sentences, i);
        word_count += sentence->words->size;
    }
    if (word_count != 17177){
        printf("Error in word count %d\n", word_count);
    }
    free_universal_dependency_tree_bank_corpus(corpus);
}