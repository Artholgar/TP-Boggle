/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Dictionnaire.h"

void range_dans_arbre(ArbreLexi * arbre, const char * mot){

	if((*arbre) == NULL){
		
		(*arbre) = allouer_noeud(mot[0]);

		if(mot[0] == '\0')
			return ;

		range_dans_arbre(&(*arbre)->fils, mot + 1);
	}else if((*arbre)->lettre > mot[0]){
		
		range_dans_arbre(&(*arbre)->fg, mot);
	}else if((*arbre)->lettre < mot[0]){

		range_dans_arbre(&(*arbre)->fd, mot);
	}else{

		range_dans_arbre(&(*arbre)->fils, mot + 1);
	}
}

int maj_a_min(int * c){

    if((*c) <= 122 && (*c) >= 97){
        return 1;
    }else if((*c) <= 90 && (*c) >= 65){
        (*c) -= 32;
        return 1;
    }else{
        return 0;
    }
}

int range_mot(ArbreLexi * arbre, char * source){
	FILE * fichier = NULL;
	char * mot;
	int c, i;

    i = 0;

	if((mot= (char *)calloc(MOTMAX, sizeof(char))) == NULL) {
		return 0;
	}

	fichier = fopen(source, "r");

	if(fichier == NULL) {
		printf("Erreur : Fichier introuvable\n");
		return 0;
	}

	/*On lit chaque caractère du texte*/
	c = fgetc(fichier);
	while (c != EOF) {

		/*Traitement d'un mot*/
		if (c != '\n' && c != '\r' && c != '\0' && i < MOTMAX) {
            if(maj_a_min(&c) == 0){
                return 0;
            }
			mot[i] = c;
			i += 1;
		}
		/*Le mot est terminé, il est temps de le traiter. Nous vérifions que ce mot n'est pas vide.*/
		else if (((int)strlen(mot)) != 0) {

			/*Mise en place dans le tableau à l'aide de Range_dans_arbre*/
			
			mot[i] = '\0'; /* On termine le mot correctement*/
			
			range_dans_arbre(arbre, mot);
			
			/*On réalloue la place pour passer au mot suivant*/
			if((mot = (char *)realloc(mot, MOTMAX * sizeof(char))) == NULL) {
				return 0;
			}
			mot[0] = '\0';
			i = 0;
		}
		c = fgetc(fichier);
	}

	
	fclose(fichier);
	return 1;
}

void afficher_dico(ArbreLexi arbre){

	if(arbre == NULL){
		return ;
	}

	if(arbre->lettre == '\0'){
		printf("\n");
	}

	

	afficher_dico(arbre->fg);
	printf("%c", arbre->lettre);
	afficher_dico(arbre->fils);
	afficher_dico(arbre->fd);
}

int est_dans_arbre(ArbreLexi arbre, char * mot){

	if(arbre == NULL){
		return 0;
	}

	if(mot[0] == '\0'){
		if(arbre->lettre == '\0'){
			return 1;
		}
		return 0;
	}

	if(arbre->lettre > mot[0]){
		return est_dans_arbre(arbre->fg, mot);
	}else if(arbre->lettre < mot[0]){
		return est_dans_arbre(arbre->fd, mot);
	}else{
		return est_dans_arbre(arbre->fils, mot + 1);
	}
}