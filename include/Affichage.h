/*
 //  Affichage.h
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */


#ifndef __AFFICHAGE__
#define __AFFICHAGE__

#include <stdio.h>
#include <assert.h>
#include <ncurses.h>
#include "Evenements.h"

/*PARAMETRES : aucun
 *RETOURS : aucun
 *EFFET DE BORD : definis et initialise stdscr
 *DESCRIPTION : Cette fonction créée la fanetre ncurses et initialise ses paramettres
 */
void init_affichage(void);

/*PARAMETRES : int abscisse, int ordonnee, int couleur, Jeu partie, int i, int j
 *RETOURS : aucun
 *EFFET DE BORD : modifie stdscr
 *DESCRIPTION : Cette fonction affiche la case de coordonnés i, j de la grille de jeu.
 */
void affiche_lettre(int abscisse, int ordonnee, int couleur, Jeu partie, int i, int j);

/*PARAMETRES : Jeu partie, int largeurC, int hauteurC
 *RETOURS : aucun
 *EFFET DE BORD : modifie stdscr
 *DESCRIPTION : Cette fonction affiche la grille de jeu.
 */
void affiche_grille(Jeu partie, int largeurC, int hauteurC);

/*PARAMETRES : int score, int vie, int largeur_quadrillage, int taille_case_largeur
 *RETOURS : aucun
 *EFFET DE BORD : modifie stdscr
 *DESCRIPTION : Cette fonction affiche le score et le nombre de vies du joueur à droite de la grille de jeu.
 */
void affiche_score_et_vie(int score, int vie, int largeur_quadrillage, int taille_case_largeur);


#endif
