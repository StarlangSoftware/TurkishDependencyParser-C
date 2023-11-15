//
// Created by Olcay Taner YILDIZ on 9.11.2023.
//

#ifndef DEPENDENCYPARSER_STANFORDDEPENDENCYRELATION_H
#define DEPENDENCYPARSER_STANFORDDEPENDENCYRELATION_H

#include "StanfordDependencyType.h"

static char *stanford_dependency_types[49] = {"acomp", "advcl", "advmod", "agent", "amod", "appos", "aux",
                                                    "auxpass", "cc", "ccomp", "conj", "cop", "csubj", "csubjpass",
                                                    "dep", "det", "discourse", "dobj", "expl", "goeswith",
                                                    "iobj", "mark", "mwe", "neg", "nn", "npadvmod", "nsubj",
                                                    "nsubjpass", "num", "number", "parataxis", "pcomp",
                                                    "pobj", "poss", "possessive", "preconj", "predet", "prep", "prepc",
                                                    "prt", "punct", "quantmod", "rcmod", "ref",
                                                    "root", "tmod", "vmod", "xcomp", "xsubj"};

static Stanford_dependency_type stanford_dependency_tags[49] = {ACOMP, ADVCL,
                                                                    ADVMOD, AGENT, AMOD, APPOS, AUX,
                                                                    AUXPASS, CC, CCOMP, CONJ, COP,
                                                                    CSUBJ, CSUBJPASS, DEP, DET, DISCOURSE,
                                                                    DOBJ, EXPL, GOESWITH, IOBJ, MARK,
                                                                    MWE, NEG, NN, NPADVMOD, NSUBJ,
                                                                    NSUBJPASS, NUM, NUMBER, PARATAXIS, PCOMP,
                                                                    POBJ, POSS, POSSESSIVE, PRECONJ, PREDET,
                                                                    PREP, PREPC, PRT, PUNCT, QUANTMOD,
                                                                    RCMOD, REF, ROOT, TMOD, VMOD,
                                                                    XCOMP, XSUBJ};

struct stanford_dependency_relation {
    int to_word;
    Stanford_dependency_type stanford_dependency_type;
};

typedef struct stanford_dependency_relation Stanford_dependency_relation;

typedef Stanford_dependency_relation *Stanford_dependency_relation_ptr;

Stanford_dependency_relation_ptr create_stanford_relation(int to_word, const char *dependency_type);

void free_stanford_relation(Stanford_dependency_relation_ptr stanford_relation);

Stanford_dependency_type get_stanford_dependency_tag(const char* tag);

#endif //DEPENDENCYPARSER_STANFORDDEPENDENCYRELATION_H
