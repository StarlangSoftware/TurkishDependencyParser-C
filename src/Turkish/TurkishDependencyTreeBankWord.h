//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKWORD_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKWORD_H

#include <MorphologicalParse.h>
#include "TurkishDependencyRelation.h"
#include "XmlElement.h"

struct turkish_dependency_tree_bank_word{
    char* name;
    Morphological_parse_ptr parse;
    Array_list_ptr original_parses;
    Turkish_dependency_relation_ptr relation;
};

typedef struct turkish_dependency_tree_bank_word Turkish_dependency_tree_bank_word;

typedef Turkish_dependency_tree_bank_word *Turkish_dependency_tree_bank_word_ptr;

Turkish_dependency_tree_bank_word_ptr create_turkish_dependency_tree_bank_word(Xml_element_ptr word_node);

void free_turkish_dependency_tree_bank_word(Turkish_dependency_tree_bank_word_ptr word);

Array_list_ptr split_into_inflectional_groups(char* IG);

Morphological_parse_ptr get_original_parse(Turkish_dependency_tree_bank_word_ptr word, int index);

#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKWORD_H
