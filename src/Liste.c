/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#include <stdlib.h>
#include <string.h>

#include "../include/Liste.h"

Liste allouerCellule(char * mot){

	Liste cel;

    if((cel = (Liste)malloc(sizeof(Cellule))) == NULL) {
		return NULL;
	}

	if((cel->mot = (char *)malloc(sizeof(char) * MOTMAX)) == NULL) {
		return NULL;
	}

	strcpy(cel->mot, mot);
	cel->suivant = NULL;

	return cel;

}

ArbreLexi allouer_noeud(char lettre){
	ArbreLexi arbre;

	arbre = (ArbreLexi)malloc(sizeof(NoeudLexi));

	arbre->lettre = lettre;
	arbre->fg = NULL;
	arbre->fd = NULL;
	arbre->fils = NULL;

	return arbre;
}