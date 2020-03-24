/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/Liste.h"
#include "../include/Dictionnaire.h"


int main(int argc, char ** argv){
    Liste lst, table_hach[TAILLEHACH];
    int i;

    lst = NULL;

    initialiseTableau(table_hach);

    rangeMots(table_hach, "Mots");

    for(i = 0; i < TAILLEHACH; i++){
        lst = table_hach[i];
        while(lst != NULL){
            printf("%s", lst->mot);
            printf("\n");
            lst = lst->suivant;
        }
        printf("---------------------------------------------\n");
    }
    
    return 0;
}
