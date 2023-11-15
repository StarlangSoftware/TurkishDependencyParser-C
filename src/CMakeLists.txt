cmake_minimum_required(VERSION 3.23)
project(DependencyParser C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(DependencyParser src/Stanford/StanfordDependencyType.h src/Turkish/TurkishDependencyType.h src/Universal/UniversalDependencyType.h src/Universal/UniversalDependencyPosType.h src/Stanford/StanfordDependencyRelation.c src/Stanford/StanfordDependencyRelation.h src/Turkish/TurkishDependencyRelation.c src/Turkish/TurkishDependencyRelation.h src/Universal/UniversalDependencyRelation.c src/Universal/UniversalDependencyRelation.h src/ParserEvaluationScore.c src/ParserEvaluationScore.h src/Turkish/TurkishDependencyTreeBankWord.c src/Turkish/TurkishDependencyTreeBankWord.h src/Universal/UniversalDependencyTreeBankWord.c src/Universal/UniversalDependencyTreeBankWord.h src/Universal/UniversalDependencyTreeBankFeatures.c src/Universal/UniversalDependencyTreeBankFeatures.h src/Turkish/TurkishDependencyTreeBankSentence.c src/Turkish/TurkishDependencyTreeBankSentence.h src/Turkish/TurkishDependencyTreeBankCorpus.c src/Turkish/TurkishDependencyTreeBankCorpus.h src/Universal/UniversalDependencyTreeBankSentence.c src/Universal/UniversalDependencyTreeBankSentence.h src/Universal/UniversalDependencyTreeBankCorpus.c src/Universal/UniversalDependencyTreeBankCorpus.h)
target_link_libraries(DependencyParser ${CONAN_LIBS})
