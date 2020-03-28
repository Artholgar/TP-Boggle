#include <stdio.h>

#include "../include/Test.h"

int test_allouer_noeud(){
    ArbreLexi arbre_test;

    arbre_test = NULL;

    arbre_test = allouer_noeud('a');

    if(NULL == arbre_test || arbre_test->lettre != 'a' || NULL != arbre_test->fg || NULL != arbre_test->fils || NULL != arbre_test->fd){
        fprintf(stderr, "ERREUR : allouer_noeud test 1\n");
        return 0;
    }

    arbre_test = allouer_noeud('\0');

    if(NULL == arbre_test || arbre_test->lettre != '\0' || NULL != arbre_test->fg || NULL != arbre_test->fils || NULL != arbre_test->fd){
        fprintf(stderr, "ERREUR : allouer_noeud test 2\n");
        return 0;
    }

    return 1;
}

int test_range_dans_arbre(){
    ArbreLexi arbre_test;

    arbre_test = NULL;

    range_dans_arbre(&arbre_test, "abcd");

    if(!est_dans_arbre(arbre_test, "abcd")){
        fprintf(stderr, "ERREUR : range_dans_arbre test 1\n");
        return 0;
    }
    
    range_dans_arbre(&arbre_test, "bcde");

    if(!est_dans_arbre(arbre_test, "abcd") || !est_dans_arbre(arbre_test, "bcde")){
        fprintf(stderr, "ERREUR : range_dans_arbre test 2\n");
        return 0;
    }

    range_dans_arbre(&arbre_test, "bcde");

    if(!est_dans_arbre(arbre_test, "abcd") || !est_dans_arbre(arbre_test, "bcde")){
        fprintf(stderr, "ERREUR : range_dans_arbre test 3\n");
        return 0;
    }

    range_dans_arbre(&arbre_test, "");

    if(!est_dans_arbre(arbre_test, "abcd") || !est_dans_arbre(arbre_test, "bcde") || est_dans_arbre(arbre_test, "")){
        fprintf(stderr, "ERREUR : range_dans_arbre test 4\n");
        return 0;
    }

    return 1;
}

int test(){
    if(!test_allouer_noeud()){
        return 0;
    }

    if(!test_range_dans_arbre()){
        return 0;
    }

    return 1;
}

