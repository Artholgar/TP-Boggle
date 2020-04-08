/*
//  Affichage.c
//  TP 7
//
//  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
*/

#include "../include/Affichage.h"


void init_affichage(){
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	
	start_color();
	
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
}


void affiche_lettre(int largeurC, int hauteurC, int couleur, Jeu partie, int i, int j){
	int x, y;
	int n, m;
	int ordonnee, abscisse;

	assert(partie.largeur > 0);
	assert(partie.hauteur > 0);
	assert(largeurC >= 0);
	assert(hauteurC >= 0);
	assert(i >= 0);
	assert(j >= 0);
	assert(i < partie.largeur);
	assert(j < partie.hauteur);

	n = 0;

	ordonnee = hauteurC * j;
	abscisse = largeurC * i;
	
	attron(COLOR_PAIR(couleur));
	
	if(partie.grille[j][i].etat)
		attron(A_STANDOUT);
	
	if(partie.pos.i == i && partie.pos.j == j)
		attron(A_BLINK);
	
	for(y = ordonnee; y < ordonnee + hauteurC; y++){
		m = 0;
		n++;
		for(x = abscisse; x < abscisse + largeurC; x++){
			if(m == largeurC / 2 && n == hauteurC / 2 + 1)
				mvprintw(y, x, "%c", partie.grille[j][i].lettre);
			else
				mvprintw(y, x, " ");
			m++;
		}
	}
	refresh();
	
	attroff(COLOR_PAIR(couleur) | A_STANDOUT | A_BLINK);
}


void affiche_grille(Jeu partie, int largeurC, int hauteurC){
	int i, j;

	assert(largeurC > 0);
	assert(hauteurC > 0);
	
	for(j = 0; j < partie.hauteur ; j++)
		for( i = 0; i < partie.largeur; i++)
			affiche_lettre(largeurC, hauteurC, (i + j) % 2 + 1, partie, i, j);
}

void affiche_score_et_vie(int score, int vie, int largeur_quadrillage, int taille_case_largeur){
	mvprintw(1, largeur_quadrillage * taille_case_largeur, "Score : %d", score);
	mvprintw(3, largeur_quadrillage * taille_case_largeur, "Tentative(s) restante(s) : %d", vie);
}
