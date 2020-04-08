/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#ifndef __DICO__
#define __DICO__

#include "Arbre.h"

#define TAILLEHACH 1000

/*PARAMETRES : ArbreLexi * arbre, const char * mot
 *RETOURS : aucun
 *EFFET DE BORD : modifie arbre
 *DESCRIPTION : Cette fonction ajoute un mot à l'arbre lexicographique arbre.
 */
void range_dans_arbre(ArbreLexi * arbre, const char * mot);

/*PARAMETRES : int * c
 *RETOURS : code d'erreur
 *EFFET DE BORD : modifie c
 *DESCRIPTION : Cette fonction modifie la lettre c, si c'est une majuscule, en la meme lettre mais minuscule.
 */
int maj_a_min(int * c);

/*PARAMETRES : ArbreLexi * arbre, const char * source
 *RETOURS : code d'erreur
 *EFFET DE BORD : modifie arbre
 *DESCRIPTION : Cette fonction ajoute tous les mots du fichier source à l'arbre lexicographique arbre.
 */
int range_mot(ArbreLexi * arbre, const char * source);

/*PARAMETRES : ArbreLexi arbre, char * mot
 *RETOURS : int
 *EFFET DE BORD : aucun
 *DESCRIPTION : Cette fonction renvoie 1 si mot apartient à arbre, 0 sinon.
 */
int est_dans_arbre(ArbreLexi arbre, char * mot);

#endif
