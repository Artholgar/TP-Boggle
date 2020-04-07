/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#ifndef __DICO__
#define __DICO__

#include "Arbre.h"

#define TAILLEHACH 1000

void range_dans_arbre(ArbreLexi * arbre, const char * mot);

int maj_a_min(int * c);

/*---------------------------------------------------------------------------*/
/* BUT : Traiter et ranger tous les mots du fichier dont le nom est passé en */
/*       paramètres dans un tableau de Listes                                */
/* PARAMETRES : tableHachage][] : Tableau de Listes des mots du texte        */
/*              *source : nom du fichier à traiter                           */
/* RETOUR : Valeur entière. 0 si erreur, 1 sinon                             */
/* EFFET DE BORD : Remplit le tableau tableHachage des Cellules des          */
/*                 différents mots du texte                                  */
/*---------------------------------------------------------------------------*/
int range_mot(ArbreLexi * arbre, const char * source);

int est_dans_arbre(ArbreLexi arbre, char * mot);

#endif
