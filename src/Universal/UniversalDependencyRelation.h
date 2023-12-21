//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H

#include "UniversalDependencyType.h"
#include "UniversalDependencyPosType.h"
#include "../ParserEvaluationScore.h"

static char* universal_dependency_types[62] = {"acl", "advcl",
                                               "advmod", "amod", "appos", "aux", "case",
                                               "cc", "ccomp", "clf", "compound", "conj",
                                               "cop", "csubj", "dep", "det", "discourse",
                                               "dislocated", "expl", "fixed", "flat",
                                               "goeswith", "iobj", "list", "mark", "nmod",
                                               "nsubj", "nummod", "obj", "obl", "orphan",
                                               "parataxis", "punct", "reparandum", "root",
                                               "vocative", "xcomp", "acl:relcl", "aux:pass",
                                               "cc:preconj", "compound:prt", "det:predet", "flat:foreign",
                                               "nsubj:pass", "csubj:pass", "nmod:npmod", "nmod:poss",
                                               "nmod:tmod", "avdmod:emph", "aux:q", "compound:lvc",
                                               "compound:redup", "csubj:cop", "nmod:comp", "nmod:part",
                                               "nsubj:cop", "obl:agent", "obl:tmod", "obl:npmod", "nsubj:outer",
                                               "csubj:outer", "advcl:relcl"};

static Universal_dependency_type universal_dependency_tags[62] = {ACL, ADVCL,
                                                                  ADVMOD, AMOD, APPOS, AUX, CASE,
                                                                  CC, CCOMP, CLF, COMPOUND, CONJ,
                                                                  COP, CSUBJ, DEP, DET, DISCOURSE,
                                                                  DISLOCATED, EXPL, FIXED, FLAT,
                                                                  GOESWITH, IOBJ, LIST, MARK, NMOD,
                                                                  NSUBJ, NUMMOD, OBJ, OBL, ORPHAN,
                                                                  PARATAXIS, PUNCT, REPARANDUM, ROOT,
                                                                  VOCATIVE, XCOMP, ACL_RELCL, AUX_PASS,
                                                                  CC_PRECONJ, COMPOUND_PRT, DET_PREDET, FLAT_FOREIGN,
                                                                  NSUBJ_PASS, CSUBJ_PASS, NMOD_NPMOD, NMOD_POSS,
                                                                  NMOD_TMOD, ADVMOD_EMPH, AUX_Q, COMPOUND_LVC,
                                                                  COMPOUND_REDUP, CSUBJ_COP, NMOD_COMP, NMOD_PART,NSUBJ_COP,
                                                                  OBL_AGENT, OBL_TMOD, OBL_NPMOD, NSUBJ_OUTER,
                                                                  CSUBJ_OUTER, ADVCL_RELCL};

static char* universal_dependency_pos_types[17] = {"ADJ", "ADV", "INTJ", "NOUN", "PROPN", "VERB", "ADP", "AUX", "CCONJ",
                                                   "DET", "NUM", "PART", "PRON", "SCONJ", "PUNCT", "SYM", "X"};

static Universal_dependency_pos_type universal_dependency_pos_tags[17] = {ADJ, ADV, INTJ, NOUN_POS2, PROPN,
                                                                          VERB_POS2, ADP, AUX_POS, CCONJ,
                                                                          DET_POS, NUM, PART,
                                                                          PRON, SCONJ,
                                                                          PUNCT_POS, SYM, X};

struct universal_dependency_relation{
    int to_word;
    Universal_dependency_type universal_dependency_type;
};

typedef struct universal_dependency_relation Universal_dependency_relation;

typedef Universal_dependency_relation *Universal_dependency_relation_ptr;

Universal_dependency_relation_ptr create_universal_dependency_relation(int to_word, const char* dependency_type);

Universal_dependency_relation_ptr create_universal_dependency_relation2(int to_word);

void free_universal_dependency_relation(Universal_dependency_relation_ptr universal_dependency_relation);

Universal_dependency_type get_universal_dependency_tag(const char* tag);

Universal_dependency_pos_type get_universal_dependency_pos_tag(const char* tag);

Parser_evaluation_score_ptr compare_relations(Universal_dependency_relation_ptr relation1, Universal_dependency_relation_ptr relation2);

Universal_dependency_relation_ptr clone_universal_dependency_relation(Universal_dependency_relation_ptr relation);

char* universal_dependency_relation_to_string(Universal_dependency_relation_ptr relation);

#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H
