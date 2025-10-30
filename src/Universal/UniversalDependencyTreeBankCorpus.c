//
// Created by Olcay Taner YILDIZ on 14.11.2023.
//

#include <StringUtils.h>
#include <Dictionary/Word.h>
#include <FileUtils.h>
#include <string.h>
#include <Memory/Memory.h>
#include "UniversalDependencyTreeBankCorpus.h"
#include "UniversalDependencyTreeBankSentence.h"

/**
 * Constructs a universal dependency corpus from an input file. Reads the sentences one by one and constructs a
 * universal dependency sentence from each line read.
 * @param file_name Input file name.
 */
Universal_dependency_tree_bank_corpus_ptr create_universal_dependency_tree_bank_corpus(const char *file_name) {
    char sentence[MAX_LINE_LENGTH], sentence1[MAX_LINE_LENGTH];
    Universal_dependency_tree_bank_corpus_ptr result = malloc_(sizeof(Universal_dependency_tree_bank_corpus));
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
            sprintf(sentence1, "%s\n%s", sentence, line);
            strcpy(sentence, sentence1);
        }
    }
    free_array_list(lines, free_);
    return result;
}

/**
 * Compares the corpus with the given corpus and returns a parser evaluation score for this comparison. The result
 * is calculated by summing up the parser evaluation scores of sentence by sentence comparisons.
 * @param corpus1 First Universal dependency corpus to be compared.
 * @param corpus2 Second Universal dependency corpus to be compared.
 * @return A parser evaluation score object.
 */
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

/**
 * Frees memory allocated to universal dependency corpus. Deallocates sentences array list.
 * @param corpus Corpus to be deallocated.
 */
void free_universal_dependency_tree_bank_corpus(Universal_dependency_tree_bank_corpus_ptr corpus) {
    free_array_list(corpus->sentences, (void (*)(void *)) free_universal_dependency_tree_bank_sentence);
    free_(corpus->language);
    free_(corpus);
}
