/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/Liste.h"
#include "../include/Dictionnaire.h"


int main(int argc, char ** argv){
    ArbreLexi arbre;
    char c;

    arbre = NULL;

    range_mot(&arbre, "Mots");

    /*range_dans_arbre(&arbre, "carabaff");

    range_dans_arbre(&arbre, "carapuce");

    range_dans_arbre(&arbre, "tortank");

    range_dans_arbre(&arbre, "autisme");

    range_dans_arbre(&arbre, "catacombes");

    range_dans_arbre(&arbre, "tortanks");*/
    
    afficher_dico(arbre);

    
    
    return 0;
}
