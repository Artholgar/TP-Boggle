/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#ifndef __DICO__
#define __DICO__

#include "Liste.h"

#define TAILLEHACH 1000

/*---------------------------------------------------------------------------*/
/* BUT : Renvoyer une valeur entière propre à un mot p passé en paramètres   */
/*       afin de pouvoir déterminer l'indice pour ranger la Cellule du mot   */
/*       dans un tableau de Listes                                           */
/* PARAMETRES : *p : mot à hacher                                            */
/* RETOUR : Valeur entière unique pour chaque mot                            */
/* EFFET DE BORD : Modifie la valeur d'une variable entière                  */
/*---------------------------------------------------------------------------*/
unsigned int hache(char *p);

/*---------------------------------------------------------------------------*/
/* BUT : Initialiser toutes les cases du tableau à NULL                      */
/* PARAMETRES : tableHachage][] : Tableau de Listes des mots du texte        */
/* RETOUR : Aucun                                                            */
/* EFFET DE BORD : Change toutes les valeurs du tableau en NULL              */
/*---------------------------------------------------------------------------*/
void initialiseTableau(Liste tableHachage[]);

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
int range_mot(ArbreLexi * arbre, char * source);

void afficher_dico(ArbreLexi arbre);

#endif