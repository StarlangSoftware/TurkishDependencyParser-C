//
// Created by Olcay Taner YILDIZ on 13.11.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "TurkishDependencyTreeBankSentence.h"
#include "TurkishDependencyTreeBankWord.h"

/**
 * Given the parsed xml node which contains information about a sentence, the method constructs a
 * TurkishDependencyTreeBankSentence from it.
 * @param sentenceNode Xml parsed node containing information about a sentence.
 */
Sentence_ptr create_turkish_dependency_tree_bank_sentence(Xml_element_ptr sentence_node) {
    Sentence_ptr sentence = create_sentence();
    Xml_element_ptr wordNode;
    Turkish_dependency_tree_bank_word_ptr word;
    wordNode = sentence_node->first_child;
    while (wordNode != NULL){
        word = create_turkish_dependency_tree_bank_word(wordNode);
        array_list_add(sentence->words, word);
        wordNode = wordNode->next_sibling;
    }
    return sentence;
}

void free_turkish_dependency_tree_bank_sentence(Sentence_ptr sentence) {
    free_array_list(sentence->words, (void (*)(void *)) free_turkish_dependency_tree_bank_word);
    free_(sentence);
}

/**
 * Calculates the maximum of all word to related word distances, where the distances are calculated in terms of
 * index differences.
 * @return Maximum of all word to related word distances.
 */
int max_dependency_length(Sentence_ptr sentence) {
    int max = 0;
    for (int i = 0; i < sentence->words->size; i++){
        Turkish_dependency_tree_bank_word_ptr word = array_list_get(sentence->words, i);
        if (word->relation->to_word - i > max){
            max = word->relation->to_word - i;
        }
    }
    return max;
}
