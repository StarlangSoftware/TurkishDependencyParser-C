//
// Created by Olcay Taner YILDIZ on 15.11.2023.
//

#include <Corpus.h>
#include <Memory/Memory.h>

#include "../src/Turkish/TurkishDependencyTreeBankCorpus.h"

int main(){
    Corpus_ptr corpus = create_turkish_dependency_tree_bank_corpus("metu-treebank.xml");
    if (corpus->sentences->size != 5635){
        printf("Error in sentence count %d\n", corpus->sentences->size);
    }
    int word_count = 0;
    for (int i = 0; i < corpus->sentences->size; i++){
        Sentence_ptr sentence = array_list_get(corpus->sentences, i);
        word_count += sentence->words->size;
    }
    if (word_count != 53993){
        printf("Error in word count %d\n", word_count);
    }
    free_turkish_dependency_tree_bank_corpus(corpus);
}