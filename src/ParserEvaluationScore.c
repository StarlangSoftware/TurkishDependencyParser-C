//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "ParserEvaluationScore.h"

Parser_evaluation_score_ptr create_parser_evaluation_score(double LAS,
                                                           double UAS,
                                                           double LS,
                                                           int word_count) {
    Parser_evaluation_score_ptr result = malloc_(sizeof(Parser_evaluation_score), "create_parser_evaluation_score");
    result->LAS = LAS;
    result->UAS = UAS;
    result->LS = LS;
    result->word_count = word_count;
    return result;
}

Parser_evaluation_score_ptr create_parser_evaluation_score2() {
    Parser_evaluation_score_ptr result = malloc_(sizeof(Parser_evaluation_score), "create_parser_evaluation_score2");
    result->LAS = 0;
    result->UAS = 0;
    result->LS = 0;
    result->word_count = 0;
    return result;
}

void add_score(Parser_evaluation_score_ptr score1, Parser_evaluation_score_ptr score2) {
    score1->LAS = (score1->LAS * score1->word_count + score2->LAS * score2->word_count) / (score1->word_count + score2->word_count);
    score1->UAS = (score1->UAS * score1->word_count + score2->UAS * score2->word_count) / (score1->word_count + score2->word_count);
    score1->LS = (score1->LS * score1->word_count + score2->LS * score2->word_count) / (score1->word_count + score2->word_count);
    score1->word_count += score2->word_count;
}
