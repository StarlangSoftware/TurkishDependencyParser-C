//
// Created by Olcay Taner YILDIZ on 13.11.2023.
//

#include <XmlDocument.h>
#include <stdlib.h>
#include <Memory/Memory.h>
#include "TurkishDependencyTreeBankCorpus.h"
#include "TurkishDependencyTreeBankSentence.h"

/**
 * Another constructor for TurkishDependencyTreeBankCorpus. The method gets the corpus as an xml file, and
 * reads sentences one by one. For each sentence, the function constructs a TurkishDependencyTreeBankSentence.
 * @param file_name Input file name to read the TurkishDependencyTreeBankCorpus.
 */
Corpus_ptr create_turkish_dependency_tree_bank_corpus(const char *file_name) {
    Corpus_ptr corpus = create_corpus();
    Xml_document_ptr doc = create_xml_document(file_name);
    Sentence_ptr sentence;
    parse(doc);
    Xml_element_ptr rootNode = doc->root;
    Xml_element_ptr sentenceNode = rootNode->first_child;
    while (sentenceNode != NULL){
        sentence = create_turkish_dependency_tree_bank_sentence(sentenceNode);
        corpus_add_sentence(corpus, sentence);
        sentenceNode = sentenceNode->next_sibling;
    }
    free_document(doc);
    return corpus;
}

void free_turkish_dependency_tree_bank_corpus(Corpus_ptr corpus) {
    free_array_list(corpus->sentences, (void (*)(void *)) free_turkish_dependency_tree_bank_sentence);
    free_array_list(corpus->paragraphs, NULL);
    free_counter_hash_map(corpus->word_list);
    free_(corpus);
}
