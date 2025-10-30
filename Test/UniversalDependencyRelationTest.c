//
// Created by Olcay Taner YILDIZ on 15.11.2023.
//

#include <stdio.h>
#include <Memory/Memory.h>

#include "../src/Universal/UniversalDependencyRelation.h"

int main(){
    start_memory_check();
    if (get_universal_dependency_pos_tag("adj") != ADJ){
        printf("Error in tag adj");
    }
    if (get_universal_dependency_pos_tag("intj") != INTJ){
        printf("Error in tag intj");
    }
    if (get_universal_dependency_pos_tag("Det") != DET_POS){
        printf("Error in tag Det");
    }
    if (get_universal_dependency_tag("acl") != ACL){
        printf("Error in tag acl");
    }
    if (get_universal_dependency_tag("iobj") != IOBJ){
        printf("Error in tag iobj");
    }
    if (get_universal_dependency_tag("Iobj") != IOBJ){
        printf("Error in tag Iobj");
    }
    if (get_universal_dependency_tag("fixed") != FIXED){
        printf("Error in tag fixed");
    }
    end_memory_check();
}