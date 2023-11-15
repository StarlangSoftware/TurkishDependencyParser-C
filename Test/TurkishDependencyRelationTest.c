//
// Created by Olcay Taner YILDIZ on 15.11.2023.
//

#include <stdio.h>
#include "../src/Turkish/TurkishDependencyRelation.h"

int main(){
    if (get_turkish_dependency_tag("subject") != SUBJECT){
        printf("Error in tag subject");
    }
    if (get_turkish_dependency_tag("vocative") != VOCATIVE){
        printf("Error in tag vocative");
    }
    if (get_turkish_dependency_tag("Relativizer") != RELATIVIZER){
        printf("Error in tag Relativizer");
    }
}