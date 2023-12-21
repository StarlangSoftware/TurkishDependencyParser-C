//
// Created by Olcay Taner YILDIZ on 11.11.2023.
//

#include <string.h>
#include <StringUtils.h>
#include <Dictionary/Word.h>
#include <FileUtils.h>
#include <Memory/Memory.h>
#include "UniversalDependencyTreeBankFeatures.h"
#include "UniversalDependencyRelation.h"

static char* universal_feature_types[25] = {"PronType", "NumType", "Poss", "Reflex", "Foreign",
                                            "Abbr", "Typo", "Gender", "Animacy", "NounClass",
                                            "Number", "Case", "Definite", "Degree", "VerbForm",
                                            "Mood", "Tense", "Aspect", "Voice", "Evident",
                                            "Polarity", "Person", "Polite", "Clusivity", "NumForm"};

static char** universal_feature_values[25] = {
        (char*[]){"Art",    "Dem",    "Emp",    "Exc",    "Ind",    "Int",    "Neg",    "Prs",    "Rcp",    "Rel",     "Tot"},
        (char*[]){"Card",   "Dist",   "Frac",   "Mult",   "Ord",    "Range",  "Sets"},
        (char*[]){"Yes"},
        (char*[]){"Yes"},
        (char*[]){"Yes"},

        (char*[]){"Yes"},
        (char*[]){"Yes"},
        (char*[]){"Com",    "Fem",    "Masc",   "Neut"},
        (char*[]){"Anim",   "Hum",    "Inan",   "Nhum"},
        (char*[]){"Bantu1", "Bantu2", "Bantu3", "Bantu4", "Bantu5", "Bantu6", "Bantu7", "Bantu8", "Bantu9", "Bantu10", "Bantu11", "Bantu12", "Bantu13", "Bantu14", "Bantu15", "Bantu16", "Bantu17", "Bantu18", "Bantu19", "Bantu20", "Bantu21", "Bantu22", "Bantu23", "Wol1", "Wol2", "Wol3", "Wol4", "Wol5", "Wol6", "Wol7", "Wol8", "Wol9", "Wol10", "Wol11", "Wol12"},

        (char*[]){"Coll",   "Count",  "Dual",   "Grpa",   "Grpl",   "Inv",    "Pauc",   "Plur",   "Ptan",   "Sing",    "Tri"},
        (char*[]){"Abs",    "Acc",    "Erg",    "Nom",    "Abe",    "Ben",    "Cau",    "Cmp",    "Cns",    "Com",     "Dat",     "Dis",     "Equ",     "Gen",     "Ins",     "Par",     "Tem",     "Tra",     "Voc",     "Abl",     "Add",     "Ade",     "All",     "Del",  "Ela",  "Ess",  "Ill",  "Ine",  "Lat",  "Loc",  "Per",  "Sbe",  "Sbl",   "Spl",   "Sub", "Sup", "Ter"},
        (char*[]){"Com",    "Cons",   "Def",    "Ind",    "Spec"},
        (char*[]){"Abs",    "Aug",    "Cmp",    "Dim",    "Equ",    "Pos",    "Sup"},
        (char*[]){"Conv",   "Fin",    "Gdv",    "Ger",    "Inf",    "Part",   "Sup",    "Vnoun"},

        (char*[]){"Adm",    "Cnd",    "Des",    "Imp",    "Ind",    "Int",    "Irr",    "Jus",    "Nec",    "Opt",     "Pot",     "Prp",     "Qot",     "Sub"},
        (char*[]){"Fut",    "Imp",    "Past",   "Pqp",    "Pres"},
        (char*[]){"Hab",    "Imp",    "Iter",   "Perf",   "Prog",   "Prosp"},
        (char*[]){"Act",    "Antip",  "Bfoc",   "Cau",    "Dir",    "Inv",    "Lfoc",   "Mid",    "Pass",   "Rcp"},
        (char*[]){"Fh",     "Nfh"},

        (char*[]){"Neg",    "Pos"},
        (char*[]){"0",      "1",      "2",      "3",      "4"},
        (char*[]){"Elev",   "Form",   "Humb",   "Infm"},
        (char*[]){"Ex",     "In"},
        (char*[]){"Word", "Digit", "Roman"}
};

static int universal_feature_values_size[25] = {11, 7, 1, 1, 1,
                                              1,1, 4, 4, 35,
                                              11, 37, 5, 7, 8,
                                              14, 5, 6, 10, 2,
                                              2, 5, 4, 2, 3};

static char** turkish_feature_values[25] = {
        (char*[]){"Art",  "Dem",  "Ind",  "Int",   "Neg",    "Prs",        "Rcp",     "Rel",        "Tot"},
        (char*[]){"Card", "Dist", "Ord"},
        (char*[]){},
        (char*[]){"Yes"},
        (char*[]){},

        (char*[]){"Yes"},
        (char*[]){},
        (char*[]){},
        (char*[]){},
        (char*[]){},

        (char*[]){"Plur", "Sing"},
        (char*[]){"Acc",  "Nom",  "Dat",  "Equ",   "Gen",    "Ins",        "Abl",     "Loc"},
        (char*[]){"Def",  "Ind"},
        (char*[]){"Cmp",  "Sup"},
        (char*[]){"Conv", "Fin",  "Part", "Vnoun"},

        (char*[]){"Cnd",  "Des",  "Gen",  "Imp",   "Ind",    "Nec",        "Opt",     "Pot",        "DesPot", "CndPot",   "CndGen",  "CndGenPot", "GenPot", "PotPot", "GenNecPot", "GenNec", "NecPot", "GenPotPot", "ImpPot"},
        (char*[]){"Fut",  "Past", "Pqp",  "Pres",  "Aor"},
        (char*[]){"Imp",  "Perf", "Prog", "Prosp", "Hab",    "Rapid"},
        (char*[]){"Cau",  "Pass", "Rcp",  "Rfl",   "CauCau", "CauCauPass", "CauPass", "CauPassRcp", "CauRcp", "PassPass", "PassRfl", "PassRcp"},
        (char*[]){"Fh",   "Nfh"},

        (char*[]){"Neg",  "Pos"},
        (char*[]){"1",    "2",    "3"},
        (char*[]){},
        (char*[]){},
        (char*[]){}
};

static int turkish_feature_values_size[25] = {9, 3, 0, 1, 0,
                                              1,0, 0, 0, 0,
                                              2, 8, 2, 2, 4,
                                              19, 5, 6, 12, 2,
                                              2, 3, 0, 0, 0};

static char** english_feature_values[25] = {
        (char*[]){"Art",  "Dem",  "Emp",  "Ind", "Int", "Neg", "Prs", "Rcp", "Rel", "Tot"},
        (char*[]){"Card", "Frac", "Mult", "Ord"},
        (char*[]){"Yes"},
        (char*[]){"Yes"},
        (char*[]){"Yes"},

        (char*[]){"Yes"},
        (char*[]){"Yes"},
        (char*[]){"Fem",  "Masc", "Neut"},
        (char*[]){},
        (char*[]){},

        (char*[]){"Plur", "Sing"},
        (char*[]){"Acc",  "Nom",  "Gen"},
        (char*[]){"Def",  "Ind"},
        (char*[]){"Cmp",  "Pos",  "Sup"},
        (char*[]){"Fin",  "Ger",  "Inf",  "Part"},

        (char*[]){"Imp",  "Ind",  "Sub"},
        (char*[]){"Past", "Pres"},
        (char*[]){},
        (char*[]){"Pass"},
        (char*[]){},

        (char*[]){"Neg"},
        (char*[]){"1",    "2",    "3"},
        (char*[]){},
        (char*[]){},
        (char*[]){"Word", "Digit", "Roman"}
};

static int english_feature_values_size[25] = {10, 4, 1, 1, 1,
                                              1,1, 3, 0, 0,
                                              2, 3, 2, 3, 4,
                                              3, 2, 0, 1, 0,
                                              1, 3, 0, 0, 3};

Universal_dependency_tree_bank_features_ptr
create_universal_dependency_tree_bank_features(const char *features) {
    Universal_dependency_tree_bank_features_ptr result = malloc_(sizeof(Universal_dependency_tree_bank_features), "create_universal_dependency_tree_bank_features");
    result->feature_list = create_string_hash_map();
    add_to_feature_list(result, features);
    return result;
}

char *get_feature_value(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features, char *feature) {
    return hash_map_get(universal_dependency_tree_bank_features->feature_list, feature);
}

bool
feature_exists(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features, char *feature) {
    return hash_map_contains(universal_dependency_tree_bank_features->feature_list, feature);
}

int
feature_index(char *feature_name) {
    int result;
    if (str_contains_c(feature_name, '[')){
        String_ptr st = substring(feature_name, 0, str_find_c(feature_name, "["));
        result = string_index(st->s, universal_feature_types, 25);
        free_string_ptr(st);
    } else {
        result = string_index(feature_name, universal_feature_types, 25);
    }
    return result;
}

int dependency_index(char *universal_dependency) {
    return string_index(universal_dependency, universal_dependency_types, 62);
}

int number_of_values(char *language, char *feature_name) {
    int index = feature_index(feature_name);
    if (index != -1){
        if (strcmp(language, "en") == 0){
            return english_feature_values_size[index];
        } else {
            if (strcmp(language, "tr") == 0){
                return turkish_feature_values_size[index];
            } else {
                return universal_feature_values_size[index];
            }
        }
    }
    return -1;
}

int feature_value_index(char *language, char *feature_name, char *feature_value) {
    char*** search_array;
    int index = feature_index(feature_name);
    if (index != -1){
        if (strcmp(language, "en") == 0){
            search_array = english_feature_values;
        } else {
            if (strcmp(language, "tr") == 0){
                search_array = turkish_feature_values;
            } else {
                search_array = universal_feature_values;
            }
        }
        for (int i = 0; i < number_of_values(language, feature_name); i++){
            if (strcmp(search_array[index][i], feature_value) == 0){
                return i;
            }
        }
        return -1;
    }
    return -1;
}

int pos_index(char *u_pos) {
    return string_index(u_pos, universal_dependency_pos_types, 17);
}

char *get_pos_string(Universal_dependency_pos_type u_pos) {
    switch (u_pos) {
        case ADJ:
            return universal_dependency_pos_types[0];
        case ADV:
            return universal_dependency_pos_types[1];
        case INTJ:
            return universal_dependency_pos_types[2];
        case NOUN_POS2:
            return universal_dependency_pos_types[3];
        case PROPN:
            return universal_dependency_pos_types[4];
        case VERB_POS2:
            return universal_dependency_pos_types[5];
        case ADP:
            return universal_dependency_pos_types[6];
        case AUX_POS:
            return universal_dependency_pos_types[7];
        case CCONJ:
            return universal_dependency_pos_types[8];
        case DET_POS:
            return universal_dependency_pos_types[9];
        case NUM:
            return universal_dependency_pos_types[10];
        case PART:
            return universal_dependency_pos_types[11];
        case PRON:
            return universal_dependency_pos_types[12];
        case SCONJ:
            return universal_dependency_pos_types[13];
        case PUNCT_POS:
            return universal_dependency_pos_types[14];
        case SYM:
            return universal_dependency_pos_types[15];
        case X:
            return universal_dependency_pos_types[16];
    }
}

void free_universal_dependency_tree_bank_features(
        Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features) {
    free_hash_map2(universal_dependency_tree_bank_features->feature_list, free_, free_);
    free_(universal_dependency_tree_bank_features);
}

char *universal_dependency_tree_bank_features_to_string(
        Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features) {
    char *result = NULL;
    if (hash_map_is_empty(universal_dependency_tree_bank_features->feature_list)){
        result = str_copy(result, "_");
        return result;
    }
    char tmp[MAX_LINE_LENGTH];
    Array_list_ptr kv_list = key_value_list(universal_dependency_tree_bank_features->feature_list);
    for (int i = 0; i < kv_list->size; i++){
        Hash_node_ptr hash_node = array_list_get(kv_list, i);
        if (i == 0){
            sprintf(tmp, "%s=%s", (char*) hash_node->key, (char*) hash_node->value);
        } else {
            sprintf(tmp, "%s|%s=%s", tmp, (char*) hash_node->key, (char*) hash_node->value);
        }
    }
    result = str_copy(result, tmp);
    return result;
}

Universal_dependency_tree_bank_features_ptr clone_universal_dependency_tree_bank_features(
        Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features) {
    Universal_dependency_tree_bank_features_ptr result = malloc_(sizeof(Universal_dependency_tree_bank_features), "clone_universal_dependency_tree_bank_features");
    result->feature_list = create_string_hash_map();
    char* features = universal_dependency_tree_bank_features_to_string(universal_dependency_tree_bank_features);
    add_to_feature_list(result, features);
    free_(features);
    return result;
}

void add_to_feature_list(Universal_dependency_tree_bank_features_ptr universal_dependency_tree_bank_features,
                         const char *features) {
    if (strcmp(features, "_") != 0){
        Array_list_ptr list = str_split(features, '|');
        for (int i = 0; i < list->size; i++){
            char* feature = array_list_get(list, i);
            Array_list_ptr items = str_split(feature, '=');
            char* feature_name = array_list_get(items, 0);
            char* feature_value = array_list_get(items, 1);
            hash_map_insert(universal_dependency_tree_bank_features->feature_list, feature_name, feature_value);
            free_array_list(items, NULL);
        }
        free_array_list(list, free_);
    }
}
