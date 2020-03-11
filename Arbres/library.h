#ifndef ARBRES_LIBRARY_H
#define ARBRES_LIBRARY_H
typedef struct _noeud {
    int val; // valeur stockee
    struct _noeud *fg, *fd; // pointeurs vers les noeuds ﬁls
} NOEUD, *ABR ;
ABR creeNoeud(int n);

typedef struct _noeud2{
    int val;
    int hauteur;
    struct _noeud2 *fg, *fd;
} NOEUD2, *AVL;

ABR insererABR(int n,ABR a);
void afficherACroissant(ABR a);
void afficherADecroissant(ABR a);
void afficherForme(ABR a,int niveau);
int rechercheN(ABR a,int n);
int valeurMax(ABR a);
void sommeEtNombres(int *somme, int *nombre, ABR a);
int hauteurArbre(ABR a,int etage);
ABR valMinArbre(ABR a);
ABR supprimerNoeud(ABR racine, int n);

int max(int a, int b);
int hauteur(AVL a);
AVL creerAVL(int n);
AVL rotationDroite(AVL a);
AVL rotationGauche(AVL b);
int getEquilibre(AVL a);
AVL reequilibrerDD(AVL a);
AVL reequilibrerDG(AVL a);
AVL reequilibrerGD(AVL a);
AVL reequilibrerGG(AVL a);
AVL reequilibrerAVL(AVL a,int n);
AVL insererValeurAVL(AVL a, int n);
#endif //ARBRES_LIBRARY_H
