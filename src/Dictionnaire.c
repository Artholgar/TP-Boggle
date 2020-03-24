/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Dictionnaire.h"

unsigned int hache(char *p){
	unsigned int h=0,g;
	for(;*p;p++){
		h=(h<<4)+*p;
		if((g=(h&0xf0000000))) /*il y a des valeurs dans les 4 bits de poids fort*/
		{
			h=h^(g>>24);/*elles vont influencer l'octet de poids faible*/
			h=h^g;/*on les supprime du haut de h*/
		}
	}
	return h;
}

void initialiseTableau(Liste tableHachage[]){
	int i = 0;
	while(i < TAILLEHACH) {
		tableHachage[i] = NULL;
		i+=1;
	}
}

int rangeDansTableau(Liste tableHachage[], char * mot, int indice){

	Liste tmp, ptr;

    tmp = NULL;

    if((tmp = allouerCellule(mot)) == NULL){
        return 0;
    }

	/*La case du tableau ne contient pas de Cellule*/
	if(tableHachage[indice] == NULL){
		/*Insérer en première position*/
		
		tableHachage[indice] = tmp;

	/*La case du tableau contient au moins une cellule*/
	}else{

        ptr = tableHachage[indice];

        while(ptr->suivant != NULL){
            ptr = ptr->suivant;
        }

        ptr->suivant = tmp;
	}
	return 1;
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

/*int rangeMots(Liste tableHachage[], char * source){
	
	FILE * fichier = NULL;
	char * mot;
	int c, i, indiceTableau;

    indiceTableau = 0;
    i = 0;

	if((mot= (char *)calloc(MOTMAX, sizeof(char))) == NULL) {
		return 0;
	}

	fichier = fopen(source, "r+");

	if(fichier == NULL) {
		printf("Erreur : Fichier introuvable\n");
		return 0;
	}

	/*On lit chaque caractère du texte*
	c = fgetc(fichier);
	while (c != EOF) {

		/*Traitement d'un mot*
		if (c != '\n' && c != '\r' && c != '\0' && i < MOTMAX) {
            if(maj_a_min(&c) == 0){
                return 0;
            }
			mot[i] = c;
			i += 1;

		}
		/*Le mot est terminé, il est temps de le traiter. Nous vérifions que ce mot n'est pas vide.*
		else if (((int)strlen(mot)) != 0) {
			

			/*Mise en place dans le tableau à l'aide de RangeDansTableau*

			mot[i] = '\0'; /* On termine le mot correctement*
			indiceTableau = hache(mot) % TAILLEHACH;
			
			rangeDansTableau(tableHachage, mot, indiceTableau);
			
			/*On réalloue la place pour passer au mot suivant*
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
}*/