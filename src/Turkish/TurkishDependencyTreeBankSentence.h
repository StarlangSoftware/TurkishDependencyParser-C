//
// Created by Olcay Taner YILDIZ on 13.11.2023.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKSENTENCE_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKSENTENCE_H

#include <Sentence.h>
#include <XmlElement.h>

Sentence_ptr create_turkish_dependency_tree_bank_sentence(Xml_element_ptr sentence_node);

void free_turkish_dependency_tree_bank_sentence(Sentence_ptr sentence);

int max_dependency_length(Sentence_ptr sentence);

#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKSENTENCE_H
