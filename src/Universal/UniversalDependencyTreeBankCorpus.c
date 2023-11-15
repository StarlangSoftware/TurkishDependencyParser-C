//
// Created by Olcay Taner YILDIZ on 14.11.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <Dictionary/Word.h>
#include <FileUtils.h>
#include <string.h>
#include "UniversalDependencyTreeBankCorpus.h"
#include "UniversalDependencyTreeBankSentence.h"

Universal_dependency_tree_bank_corpus_ptr create_universal_dependency_tree_bank_corpus(const char *file_name) {
    char sentence[MAX_LINE_LENGTH];
    Universal_dependency_tree_bank_corpus_ptr result = malloc(sizeof(Universal_dependency_tree_bank_corpus));
    String_ptr st = substring(file_name, 0, str_find_c(file_name, "_"));
    result->language = str_copy(result->language, st->s);
    result->sentences = create_array_list();
    free_string_ptr(st);
    Array_list_ptr lines = read_lines(file_name);
    sprintf(sentence, "");
    for (int i = 0; i < lines->size; i++){
        char* line = array_list_get(lines, i);
        if (strlen(line) == 0){
            Universal_dependency_tree_bank_sentence_ptr tree_bank_sentence = create_universal_dependency_tree_bank_sentence(result->language, sentence);
            array_list_add(result->sentences, tree_bank_sentence);
            sprintf(sentence, "");
        } else {
            sprintf(sentence, "%s\n%s", sentence, line);
        }
    }
    free_array_list(lines, free);
    return result;
}

Parser_evaluation_score_ptr
compare_parses(Universal_dependency_tree_bank_corpus_ptr corpus1, Universal_dependency_tree_bank_corpus_ptr corpus2) {
    Parser_evaluation_score_ptr score = create_parser_evaluation_score2();
    for (int i = 0; i < corpus1->sentences->size; i++){
        Universal_dependency_tree_bank_sentence_ptr sentence1 = array_list_get(corpus1->sentences, i);
        Universal_dependency_tree_bank_sentence_ptr sentence2 = array_list_get(corpus2->sentences, i);
        add_score(score, compare_sentences(sentence1, sentence2));
    }
    return score;
}

void free_universal_dependency_tree_bank_corpus(Universal_dependency_tree_bank_corpus_ptr corpus) {
    free_array_list(corpus->sentences, free);
    free(corpus->language);
    free(corpus);
}
