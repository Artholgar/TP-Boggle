/*Auteurs :                Guillaume MULIER, Arthur PAIRAUD
 *Date de création :       17-03-2020
 *Dates de modifications:  17-03-2020
 */

#ifndef __ARBRE__
#define __ARBRE__

#define MOTMAX 50

typedef struct noeud{
	char lettre;
	struct noeud * fg;
	struct noeud * fd;
	struct noeud * fils;
}NoeudLexi, * ArbreLexi;

/*PARAMETRES : char lettre
 *RETOURS : ArbreLexi
 *EFFET DE BORD : aucun
 *DESCRIPTION : Cette fonction renvoie un ArbreLexi qui à comme attribut lettre 
 *le caractere passé en argument, tous ses autres attributs sont initialisés à NULL.
 */
ArbreLexi allouer_noeud(char lettre);

#endif