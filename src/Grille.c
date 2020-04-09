/*
 //  Grille.c
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */


#include "../include/Grille.h"

char lettre_aleatoire(){
	/*tableau des probabilités des 26 lettres en pourcentage*/
	int proba[26] = {7, 2, 3, 4, 11, 2, 2, 5, 7, 1, 1, 4, 3, 7, 7, 2, 1, 6, 7, 8, 3, 1, 2, 1, 2, 1};
	int i = 0, nombre;
	
	
	
	nombre = 1 + (int) (100.0 * rand() / (RAND_MAX + 1.0));
	
	
	while (nombre >0)
		nombre -= proba[i++];
	
	return (char)'A' + i-1;
}

int genere_grille (Cellule *** grille, int largeur, int hauteur) {
	int i, j;
	
	if(((* grille) = (Cellule **) malloc(hauteur * sizeof(Cellule *))) == NULL)
		return 0;
	
	for (j = 0; j < hauteur; j++)
		if (((* grille) [j] = (Cellule *) malloc(largeur * sizeof(Cellule))) == NULL) 
			return 0;
	
	for (j = 0; j < hauteur; j++)
		for(i = 0; i < largeur; i++) {
			(* grille)[j][i].lettre = lettre_aleatoire();
			(* grille)[j][i].etat = 0;
		}
		
	return 1 ;
}

void reset_etat(Cellule ** grille, int largeur_quadrillage, int hauteur_quadrillage){
	int j, i;
	for(j = 0; j < hauteur_quadrillage; j++)
		for(i = 0; i < largeur_quadrillage; i++)
			grille[j][i].etat = 0;
}



