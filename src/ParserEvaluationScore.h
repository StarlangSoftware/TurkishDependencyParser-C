//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#ifndef DEPENDENCYPARSER_PARSEREVALUATIONSCORE_H
#define DEPENDENCYPARSER_PARSEREVALUATIONSCORE_H

struct parser_evaluation_score{
    double LAS;
    double UAS;
    double LS;
    int word_count;
};

typedef struct parser_evaluation_score Parser_evaluation_score;

typedef Parser_evaluation_score *Parser_evaluation_score_ptr;

Parser_evaluation_score_ptr create_parser_evaluation_score(double LAS,
                                                           double UAS,
                                                           double LS,
                                                           int word_count);

Parser_evaluation_score_ptr create_parser_evaluation_score2();

void add_score(Parser_evaluation_score_ptr score1, Parser_evaluation_score_ptr score2);

#endif //DEPENDENCYPARSER_PARSEREVALUATIONSCORE_H
