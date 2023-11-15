//
// Created by Olcay Taner YILDIZ on 9.11.2023.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYRELATION_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYRELATION_H

#include "TurkishDependencyType.h"

static char *turkish_dependency_types[23] = {"VOCATIVE", "SUBJECT", "DATIVE.ADJUNCT", "OBJECT", "POSSESSOR",
                                             "MODIFIER", "S.MODIFIER", "ABLATIVE.ADJUNCT", "DETERMINER", "SENTENCE",
                                             "CLASSIFIER", "LOCATIVE.ADJUNCT", "COORDINATION", "QUESTION.PARTICLE",
                                             "INTENSIFIER",
                                             "INSTRUMENTAL.ADJUNCT", "RELATIVIZER", "NEGATIVE.PARTICLE", "ETOL",
                                             "COLLOCATION",
                                             "FOCUS.PARTICLE", "EQU.ADJUNCT", "APPOSITION"};

static Turkish_dependency_type turkish_dependency_tags[23] = {VOCATIVE, SUBJECT, DATIVE_ADJUNCT, OBJECT, POSSESSOR,
                                                              MODIFIER, S_MODIFIER, ABLATIVE_ADJUNCT, DETERMINER_T,
                                                              SENTENCE,
                                                              CLASSIFIER, LOCATIVE_ADJUNCT, COORDINATION,
                                                              QUESTION_PARTICLE, INTENSIFIER,
                                                              INSTRUMENTAL_ADJUNCT, RELATIVIZER, NEGATIVE_PARTICLE,
                                                              ETOL, COLLOCATION,
                                                              FOCUS_PARTICLE, EQU_ADJUNCT, APPOSITION};

struct turkish_dependency_relation {
    int to_IG;
    int to_word;
    Turkish_dependency_type turkish_dependency_type;
};

typedef struct turkish_dependency_relation Turkish_dependency_relation;

typedef Turkish_dependency_relation *Turkish_dependency_relation_ptr;

Turkish_dependency_relation_ptr create_turkish_relation(int to_word, int to_IG, const char *dependency_type);

void free_turkish_relation(Turkish_dependency_relation_ptr turkish_relation);

Turkish_dependency_type get_turkish_dependency_tag(const char* tag);

#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYRELATION_H
