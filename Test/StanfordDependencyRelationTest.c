//
// Created by Olcay Taner YILDIZ on 15.11.2023.
//

#include <stdio.h>
#include "../src/Stanford/StanfordDependencyRelation.h"

int main(){
    if (get_stanford_dependency_tag("ACOMP") != ACOMP){
        printf("Error in tag ACOMP");
    }
    if (get_stanford_dependency_tag("DISCOURSE") != DISCOURSE){
        printf("Error in tag DISCOURSE");
    }
    if (get_stanford_dependency_tag("Iobj") != IOBJ){
        printf("Error in tag Iobj");
    }
    if (get_stanford_dependency_tag("IOBJ") != IOBJ){
        printf("Error in tag IOBJ");
    }
}