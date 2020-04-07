/*
 //  Affichage.h
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */


#ifndef Affichage_h
#define Affichage_h

#include <stdio.h>
#include <ncurses.h>
#include "Evenements.h"

#define COLOR_DARK_GREY 8
#define COLOR_LIGHT_GREY 9

void init_affichage(void);
void affiche_lettre(int largeur, int hauteur, int abscisse, int ordonnee, int couleur, Jeu partie, int i, int j);
void affiche_grille(Jeu partie, int largeurC, int hauteurC);
void affiche_score_et_vie(int score, int vie, int largeur_quadrillage, int taille_case_largeur);


#endif /* Affichage_h */
