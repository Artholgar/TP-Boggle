/*
 //  Grille.h
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */


#ifndef Grille_h
#define Grille_h

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int etat;
	char lettre;
}Cellule;

char lettre_aleatoire(void);

int genere_grille (Cellule *** grille, int largeur, int hauteur) ;

#endif /* Grille_h */
