/*
 //  Evenements.c
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */

#ifndef __EVENEMENT__
#define __EVENEMENT__

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

/*PARAMETRES : Cellule ** grille, int largeur_quadrillage, int hauteur_quadrillage
 *RETOURS : aucun
 *EFFET DE BORD : modifie grille
 *DESCRIPTION : Cette fonction remet à 0 tous les attributs etat des Cellule dans le tableau à deux dimantions grille.
 */
void reset_etat(Cellule ** grille, int largeur_quadrillage, int hauteur_quadrillage);

/*PARAMETRES : int y, int x, int y_prec, int x_prec
 *RETOURS : int
 *EFFET DE BORD : aucun
 *DESCRIPTION : Cette fonction revoie 1 si la case courant des voisine de la case precedante, 0 sinon.
 */
int case_valide(int y, int x, int y_prec, int x_prec);

/*PARAMETRES : Jeu * partie
 *RETOURS : aucun
 *EFFET DE BORD : modifie partie
 *DESCRIPTION : Cette fonction ajoute un caractere à la fin de l'attribur mot_actuel de partie.
 */
void ajoute_caractere(Jeu * partie);

/*PARAMETRES : Jeu * partie
 *RETOURS : aucun
 *EFFET DE BORD : modifie partie
 *DESCRIPTION : Cette fonction calcule et actualise l'attribut score de partie.
 */
void actualise_score(Jeu * partie);

/*PARAMETRES : Jeu * partie, int ev
 *RETOURS : aucun
 *EFFET DE BORD : modifie partie
 *DESCRIPTION : Cette fonction choisis quelle action effectuer en fonction de la touche qui à été pressée.
 */
void gestion_ev(Jeu * partie, int ev);

#endif
