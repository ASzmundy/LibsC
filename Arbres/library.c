#include "library.h"
#include <stdlib.h>
#include <stdio.h>
ABR creeNoeud(int n){
    ABR nouveau= (ABR)malloc(sizeof(NOEUD));
    if(nouveau){
        nouveau->val=n;
        nouveau->fg=NULL;
        nouveau->fd=NULL;
    }
    return nouveau;
}

ABR insererABR(int n,ABR a){
    if(!a){
        return creeNoeud(n);
    }else{
        if(n<=a->val){
            a->fg=insererABR(n,a->fg);
        }else{
            a->fd=insererABR(n,a->fd);
        }
    }
    return a;
}

void afficherACroissant(ABR a){
    if(a){
        afficherACroissant(a->fg);
        printf("%d",a->val);
        afficherACroissant(a->fd);
    }
}
void afficherADecroissant(ABR a){
    if(a){
        afficherADecroissant(a->fd);
        printf("%d",a->val);
        afficherADecroissant(a->fg);
    }
}

void afficherForme(ABR a,int niveau) {
    int i;
    if (a) {
        if (a->fd) {
            afficherForme(a->fd, niveau++);
        }
        for (i = 0; i < niveau * 2; i++) {
            printf("%c",'-');
        }
        printf("%d\n",a->val);
        if(a->fg){
            afficherForme(a->fg,niveau+1);
        }
    }
}

int rechercheN(ABR a,int n){
    if(a){
        if(a->val==n){
            return 1;
        }
        if(a->fd&&a->fg) {
            if (rechercheN(a->fd, n) == 0) {
                return rechercheN(a->fg, n);
            } else {
                return rechercheN(a->fd, n);
            }
        }else{
            if(a->fd){
                return rechercheN(a->fd,n);
            }else{
                return rechercheN(a->fg,n);
            }
        }
    }
    return 0;
}

int valeurMax(ABR a){
    if(a){
        if(a->fd) {
            return valeurMax(a->fd);
        }else{
            return a->val;
        }
    }else return 0;
}

void sommeEtNombres(int *somme, int *nombre, ABR a){
    if (a){
        *somme += a->val;
        *nombre = *nombre + 1;
        if(a->fd){
            sommeEtNombres(somme,nombre,a->fd);
        }
        if(a->fg){
            sommeEtNombres(somme,nombre,a->fd);
        }
    }
}

int hauteurArbre(ABR a,int etage){
    if(a){
        etage++;
        if(a->fd||a->fg) {
            if (hauteurArbre(a->fd, etage) > hauteurArbre(a->fg, etage)) {
                return hauteurArbre(a->fd, etage);
            } else return hauteurArbre(a->fg, etage);
        }
    }return etage;
}

ABR valMinArbre(ABR a){
    ABR actuel = a;
    while(actuel&&actuel->fg){
        actuel=actuel->fg;
    }
    return actuel;
}

ABR supprimerNoeud(ABR racine, int n){
    if(racine==NULL) return racine;
    if(n<racine->val){
        racine->fg=supprimerNoeud(racine->fg,n);
    }
    else if (n > racine->val){
        racine->fd=supprimerNoeud(racine->fg,n);
    }
    else{
        if(racine->fg==NULL){
            ABR temp = racine->fd;
            free(racine);
            return temp;
        }
        else if (racine->fd==NULL){
            ABR temp = racine->fg;
            free(racine);
            return temp;
        }
        ABR temp = valMinArbre(racine->fd);
        racine->val=temp->val;
        racine->fd=supprimerNoeud(racine->fd,temp->val);
    }
    return racine;
}

int max(int a, int b){
    return (a>b)? a:b;
}

int hauteur(AVL a){
    if(a==NULL) return 0;
    return a->hauteur;
}

AVL creerAVL(int n){
    AVL nouveau = (AVL)malloc(sizeof(NOEUD2));
    nouveau->val=n;
    nouveau->fd=NULL;
    nouveau->fg=NULL;
    nouveau->hauteur=1;
    return(nouveau);
}

AVL rotationDroite(AVL a){
    AVL b = a->fg;
    AVL c = b->fd;

    b->fd=a;
    a->fg=c;

    a->hauteur=max(hauteur(a->fg),hauteur(a->fd))+1;
    b->hauteur=max(hauteur(b->fg),hauteur(b->fd))+1;

    return b;
}

AVL rotationGauche(AVL b){
    AVL a = b->fd;
    AVL c = a->fg;

    a->fg=b;
    b->fd=c;

    b->hauteur=max(hauteur(b->fg),hauteur(b->fd))+1;
    a->hauteur=max(hauteur(a->fg),hauteur(a->fd))+1;

    return a;
}

int getEquilibre(AVL a){
    if(a==NULL) return 0;
    return hauteur(a->fg)-hauteur(a->fd);
}

AVL reequilibrerDD(AVL a){
    return rotationGauche(a);
}

AVL reequilibrerGG(AVL a){
    return rotationDroite(a);
}

AVL reequilibrerGD(AVL a){
    a->fg=rotationGauche(a->fg);
    return rotationDroite(a);
}

AVL reequilibrerDG(AVL a){
    a->fd=rotationDroite(a->fd);
    return rotationGauche(a);
}

AVL reequilibrerAVL(AVL a,int n){
    int equilibre = getEquilibre(a);
    if(equilibre>1 && n < a->fg->val){
        return reequilibrerGG(a);
    }
    if(equilibre<-1&&n > a->fd->val){
        return reequilibrerDD(a);
    }
    if(equilibre>1&&n > a->fg->val){
        return reequilibrerGD(a);
    }
    if(equilibre<-1&&n<a->fd->val){
        return reequilibrerDG(a);
    }
    return a;
}

AVL insererValeurAVL(AVL a, int n){
    if(a==NULL) return(creerAVL(n));

    if(n<a->val) a->fg = insererValeurAVL(a->fg,n);
    else if (n>a->val) a->fd = insererValeurAVL(a->fd,n);
    else return a;

    a->hauteur = 1+max(hauteur(a->fg),hauteur(a->fd));
    reequilibrerAVL(a,n);
    return a;
}

