/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#include <stdlib.h>
#include <string.h>

#include "../include/Arbre.h"

ArbreLexi allouer_noeud(char lettre){
	ArbreLexi arbre;

	if(NULL == (arbre = (ArbreLexi)malloc(sizeof(NoeudLexi)))){
		return NULL;
	}

	arbre->lettre = lettre;
	arbre->fg = NULL;
	arbre->fd = NULL;
	arbre->fils = NULL;

	return arbre;
}