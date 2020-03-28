/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#ifndef __LISTE__
#define __LISTE__

#define MOTMAX 50

typedef struct cellule{
	char * mot;
	struct cellule *suivant;
}Cellule, *Liste; /* pour les listes chainees de mots*/

typedef struct noeud{
	char lettre;
	struct noeud * fg;
	struct noeud * fd;
	struct noeud * fils;
}NoeudLexi, * ArbreLexi;

ArbreLexi allouer_noeud(char lettre);

#endif