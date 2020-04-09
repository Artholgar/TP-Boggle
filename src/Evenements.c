/*
 //  Evenements.c
 //  TP 7
 //
 //  Created by Guillaume Mulier and Arthur Pairaud on 26/03/2020.
*/


#include "../include/Evenements.h"

int case_valide(int y, int x, int y_prec, int x_prec){

	if(y <= y_prec + 1 && y >= y_prec - 1)
		if(x <= x_prec + 1 && x >= x_prec - 1)
			return 1;
	return 0;
}

void ajoute_caractere(Jeu * partie){
	int longeur;

	assert((*partie).grille != NULL);
	assert((*partie).pos.j >= 0);
	assert((*partie).pos.i >= 0);
	assert((*partie).pos.j < (*partie).hauteur);
	assert((*partie).pos.i < (*partie).largeur);

	longeur = strlen((*partie).mot_actuel);

	(*partie).mot_actuel[longeur] = (*partie).grille[(*partie).pos.j][(*partie).pos.i].lettre;
	(*partie).mot_actuel[longeur + 1] = '\0';
}

void actualise_score(Jeu * partie){
	int taille_mot;

	assert((*partie).score >= 0);
	
	taille_mot = strlen((*partie).mot_actuel);
	
	(*partie).score += pow(2, taille_mot - 3);

}

void gestion_ev(Jeu * partie, int ev){
	switch (ev) {
		case KEY_UP:
			if((*partie).pos.j > 0)
				(*partie).pos.j--;
			break;
			
		case KEY_DOWN:
			if((*partie).pos.j < (*partie).hauteur - 1)
				(*partie).pos.j++;
			break;
			
		case KEY_LEFT:
			if((*partie).pos.i > 0)
				(*partie).pos.i--;
			break;
			
		case KEY_RIGHT:
			if((*partie).pos.i < (*partie).largeur - 1)
				(*partie).pos.i++;
			break;
		case ' ':
			if((*partie).pos.i_precedent == -1 && (*partie).pos.j_precedent == -1){
				(*partie).pos.i_precedent = (*partie).pos.i;
				(*partie).pos.j_precedent = (*partie).pos.j;
			}
			
			if (case_valide((*partie).pos.j, (*partie).pos.i, (*partie).pos.j_precedent, (*partie).pos.i_precedent))
				if((*partie).grille[(*partie).pos.j][(*partie).pos.i].etat == 0){
					(*partie).grille[(*partie).pos.j][(*partie).pos.i].etat = 1;
					(*partie).pos.i_precedent = (*partie).pos.i;
					(*partie).pos.j_precedent = (*partie).pos.j;
					ajoute_caractere(partie);
				}
			break;
		
		case 'r':
			reset_etat((*partie).grille, (*partie).largeur, (*partie).hauteur);
			(*partie).pos.i = 0;
			(*partie).pos.j = 0;
			(*partie).pos.i_precedent = -1;
			(*partie).pos.j_precedent = -1;
			(*partie).mot_actuel[0] = '\0';
			
		case '\n':
			if(est_dans_arbre((*partie).mots, (*partie).mot_actuel)){
				(*partie).vie--;
			}
			else{
				if(est_dans_arbre((*partie).dico, (*partie).mot_actuel)){
					range_dans_arbre(&((*partie).mots), (*partie).mot_actuel);
					
					actualise_score(partie);
				}
				else {
					(*partie).vie--;
				}
			}
			
			reset_etat((*partie).grille, (*partie).largeur, (*partie).hauteur);
			(*partie).pos.i = 0;
			(*partie).pos.j = 0;
			(*partie).pos.i_precedent = -1;
			(*partie).pos.j_precedent = -1;
			(*partie).mot_actuel[0] = '\0';
	}
}
