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
void _afficherFormeABR(ABR a,int niveau);
void afficherFormeABR(ABR a);
int rechercheN(ABR a,int n);
int valeurMaxABR(ABR a);
void sommeEtNombres(int *somme, int *nombre, ABR a);
int hauteurABR(ABR a);
int valMinABR(ABR a);
ABR supprimerNoeud(ABR racine, int n);

int max(int a, int b);
int hauteurAVL(AVL a);
AVL creerAVL(int n);
AVL rotationDroite(AVL a);
AVL rotationGauche(AVL b);
int getEquilibre(AVL a);
AVL reequilibrerDD(AVL a);
AVL reequilibrerDG(AVL a);
AVL reequilibrerGD(AVL a);
AVL reequilibrerGG(AVL a);
AVL reequilibrerAVLIns(AVL a,int n);
AVL insererValeurAVL(AVL a, int n);
AVL noeudValMin(AVL a);
AVL reequilibrerAVLSup(AVL a);
AVL supprimerValeurAVL(AVL racine,int n);
void _afficherFormeAVL(AVL a, int niveau);
void afficherFormeAVL(AVL a);
#endif //ARBRES_LIBRARY_H
