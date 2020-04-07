#include <stdio.h>

#include "../include/Test.h"

/*int test_allouer_noeud(){
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

int test_lettre_aleatoire(){
	int count[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char c;
	
	int i = 100000;
	
	srand(time(NULL));
	
	while (i--) {
		printf("%c",c = lettre_aleatoire());
		count[c - 'A']++;
	}
	printf("\n");
	
	for (i = 0; i < 26; i++)
		printf("%c : %5d, %#5.2f %% \n",(char)'A' + i, count[i], count[i] / 1000.0);
		
	return 1;
}

int test_genere_grille(int largeur, int hauteur){
	char **tab;
	int i, j;
	
	tab = genere_grille(largeur, hauteur);
	
	if(tab){
		for(j = 0; j < hauteur; j++){
			for(i = 0; i < largeur; i++)
				printf("%c", tab[j][i]);
			printf("\n");
		}
		return 1;
	}
	
	return 0;
}

int test_genere_etat_grille(int largeur, int hauteur){
	int **etat;
	int i, j;
	
	etat = genere_etat_grille(largeur, hauteur);
	
	if(etat){
		for(j = 0; j < hauteur; j++){
			for(i = 0; i < largeur; i++)
				printf("%c", etat[j][i]);
			printf("\n");
		}
		return 1;
	}
	
	return 0;
}



int test(){
	if(test_allouer_noeud && test_range_dans_arbre && test_lettre_aleatoire && test_genere_grille(4, 4) && test_genere_etat_grille(4, 4))
		return 1;
	return 0;
}*/

