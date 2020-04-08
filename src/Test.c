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

	arbre_test = allouer_noeud('z');

    if(NULL == arbre_test || arbre_test->lettre != 'z' || NULL != arbre_test->fg || NULL != arbre_test->fils || NULL != arbre_test->fd){
        fprintf(stderr, "ERREUR : allouer_noeud test 2\n");
        return 0;
    }

    arbre_test = allouer_noeud('\0');

    if(NULL == arbre_test || arbre_test->lettre != '\0' || NULL != arbre_test->fg || NULL != arbre_test->fils || NULL != arbre_test->fd){
        fprintf(stderr, "ERREUR : allouer_noeud test 3\n");
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

int test_genere_grille(){
	Cellule **tab;
	int i, j, largeur, hauteur;

	largeur = 4;

	hauteur = 4;
	
	if (!genere_grille(&tab, largeur, hauteur)) {
		return 0;
	}
	
	for(j = 0; j < hauteur; j++){
		for(i = 0; i < largeur; i++){
			if (tab[j][i].lettre < 65 || tab[j][i].lettre > 90 || tab[j][i].etat < 0 || tab[j][i].etat > 1) {
				fprintf(stderr, "ERREUR : genere_grille test 1\n");
				return 0;
			}
		}
			
	}

	largeur = 8;

	hauteur = 4;
	
	if (!genere_grille(&tab, largeur, hauteur)) {
		return 0;
	}
	
	for(j = 0; j < hauteur; j++){
		for(i = 0; i < largeur; i++){
			if (tab[j][i].lettre < 65 || tab[j][i].lettre > 90 || tab[j][i].etat < 0 || tab[j][i].etat > 1) {
				fprintf(stderr, "ERREUR : genere_grille test 2\n");
				return 0;
			}
		}
			
	}

	largeur = 4;

	hauteur = 8;
	
	if (!genere_grille(&tab, largeur, hauteur)) {
		return 0;
	}
	
	for(j = 0; j < hauteur; j++){
		for(i = 0; i < largeur; i++){
			if (tab[j][i].lettre < 65 || tab[j][i].lettre > 90 || tab[j][i].etat < 0 || tab[j][i].etat > 1) {
				fprintf(stderr, "ERREUR : genere_grille test 3\n");
				return 0;
			}
		}
			
	}

	largeur = 0;

	hauteur = 0;
	
	if (!genere_grille(&tab, largeur, hauteur)) {
		return 0;
	}
	
	for(j = 0; j < hauteur; j++){
		for(i = 0; i < largeur; i++){
			if (tab[j][i].lettre < 65 || tab[j][i].lettre > 90 || tab[j][i].etat < 0 || tab[j][i].etat > 1) {
				fprintf(stderr, "ERREUR : genere_grille test 4\n");
				return 0;
			}
		}
			
	}
	return 1;

}

int test(){
	if(test_allouer_noeud() && test_range_dans_arbre() && test_genere_grille())
		return 1;
	return 0;
}

