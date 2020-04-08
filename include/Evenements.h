/*
 //  Evenements.c
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */

#ifndef Evenements_h
#define Evenements_h

#include <stdio.h>
#include <assert.h>
#include <ncurses.h>
#include <string.h>
#include <math.h>
#include "Grille.h"
#include "Dictionnaire.h"

typedef struct curseur{
	int 	i;
	int		j;
	int		i_precedent;
	int		j_precedent;

}Curseur;

typedef struct jeu{
	int largeur;
	int hauteur;
	Cellule ** grille;
	ArbreLexi dico;
	ArbreLexi mots;
	char mot_actuel[32];
	int vie;
	int score;
	Curseur pos;
}Jeu;

void reset_etat(Cellule ** grille, int largeur_quadrillage, int hauteur_quadrillage);
int case_valide(int y, int x, int y_prec, int x_prec);
void ajoute_caractere(Jeu * partie);
void actualise_score(Jeu * partie);
void gestion_ev(Jeu * partie, int ev);

#endif /* Evenements_h */
