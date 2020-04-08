/*
 //  main.c
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "../include/Affichage.h"
#include "../include/Grille.h"
#include "../include/Evenements.h"
#include "../include/Test.h"

int main(int argc, const char * argv[]){
	int largeur_case, hauteur_case;
	int touche;

	Jeu partie;

	partie.largeur = 10;
	partie.hauteur = 10;
	partie.score = 0;
	partie.vie = 4;
	partie.dico = NULL;
	partie.mots = NULL;
	partie.grille = NULL;
	partie.pos.j = 0;
	partie.pos.i = 0;
	partie.pos.j_precedent = -1;
	partie.pos.i_precedent = -1;
	partie.mot_actuel[0] = '\0';

	largeur_case = 7;
	hauteur_case = 3;

	if(!test()) {
		exit(EXIT_FAILURE);
	}
	
	srand((unsigned)(time(NULL)));
	if(range_mot(&(partie.dico), "./Mots") == 0)
		if(range_mot(&(partie.dico), "../Mots") == 0)
			exit(EXIT_FAILURE);		
	
	init_affichage();
	
	if (genere_grille(&(partie.grille), partie.largeur, partie.hauteur) == 0) 
		exit(EXIT_FAILURE);

	do {
		affiche_grille(partie, largeur_case, hauteur_case);
		
		affiche_score_et_vie(partie.score, partie.vie, partie.largeur, largeur_case);
		
		touche = getch();
		
		gestion_ev(&partie, touche);
	} while (partie.vie != 0);

	affiche_score_et_vie(partie.score, partie.vie, partie.largeur, largeur_case);
	
	getch();
	
	endwin();
	return 0;
}
