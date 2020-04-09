/*
 //  Grille.h
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */


#ifndef __GRILLE__
#define __GRILLE__

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int etat;
	char lettre;
}Cellule;

/*PARAMETRES : aucun
 *RETOURS : char
 *EFFET DE BORD : aucun
 *DESCRIPTION : Cette fonction revoie un lettre aleatoire en fonction des probabilités de chaque lettre.
 */
char lettre_aleatoire(void);

/*PARAMETRES : Cellule *** grille, int largeur, int hauteur
 *RETOURS : code d'erreur
 *EFFET DE BORD : modifie grille
 *DESCRIPTION : Cette fonction alloue et initialise grille en un tableau de hauteur x largeur.
 */
int genere_grille (Cellule *** grille, int largeur, int hauteur) ;

/*PARAMETRES : Cellule ** grille, int largeur_quadrillage, int hauteur_quadrillage
 *RETOURS : aucun
 *EFFET DE BORD : modifie grille
 *DESCRIPTION : Cette fonction remet à 0 tous les attributs etat des Cellule dans le tableau à deux dimantions grille.
 */
void reset_etat(Cellule ** grille, int largeur_quadrillage, int hauteur_quadrillage);

#endif
