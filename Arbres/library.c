#include "library.h"
#include <stdlib.h>
#include <stdio.h>

//ABR

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

void _afficherFormeABR(ABR a,int niveau) {
    if(a) {
        _afficherFormeABR(a->fd, niveau + 1);
        for (int i = 1; i <= niveau; i++)
            printf("--");
        printf("%d\n", a->val);
        _afficherFormeABR(a->fg, niveau + 1);
    }
}

void afficherFormeABR(ABR a){
    _afficherFormeABR(a,0);
}

int rechercheN(ABR a,int n){
    if(a){
        if(a->val==n)
            return 1;
        else if (n<a->val) return rechercheN(a->fg,n);
        else return rechercheN(a->fd,n);
    }
    return 0;
}

int valeurMaxABR(ABR a){
    if(a){
        if(a->fd) {
            return valeurMaxABR(a->fd);
        }else{
            return a->val;
        }
    }else return -1;
}

void sommeEtNombres(int *somme, int *nombre, ABR a){
    if (a){
        *somme += a->val;
        *nombre = *nombre + 1;
            sommeEtNombres(somme,nombre,a->fd);
            sommeEtNombres(somme,nombre,a->fd);
    }
}

int hauteurABR(ABR a){
    int h=-1;
    if(a){
        if(!(a->fd)&&!(a->fg)) {
            h=0;
        } else h=1+max(hauteurABR(a->fg), hauteurABR(a->fd));
    }return h;
}

int valMinABR(ABR a){
    if(a) {
        ABR actuel = a;
        while (actuel && actuel->fg) {
            actuel = actuel->fg;
        }
        return actuel->val;
    } return 0;
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
        int temp = valMinABR(racine->fd);
        racine->val=temp;
        racine->fd=supprimerNoeud(racine->fd,temp);
    }
    return racine;
}

//AVL

int max(int a, int b){
    return (a>b)? a:b;
}

int hauteurAVL(AVL a){
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

    a->hauteur=max(hauteurAVL(a->fg),hauteurAVL(a->fd))+1;
    b->hauteur=max(hauteurAVL(b->fg),hauteurAVL(b->fd))+1;

    return b;
}

AVL rotationGauche(AVL b){
    AVL a = b->fd;
    AVL c = a->fg;

    a->fg=b;
    b->fd=c;

    b->hauteur=max(hauteurAVL(b->fg),hauteurAVL(b->fd))+1;
    a->hauteur=max(hauteurAVL(a->fg),hauteurAVL(a->fd))+1;

    return a;
}

int getEquilibre(AVL a){
    if(a==NULL) return 0;
    return hauteurAVL(a->fg)-hauteurAVL(a->fd);
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

AVL reequilibrerAVLIns(AVL a,int n){
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

    a->hauteur = 1+max(hauteurAVL(a->fg),hauteurAVL(a->fd));
    a=reequilibrerAVLIns(a,n);
    return a;
}

AVL noeudValMin(AVL a){
    AVL actuel=a;
    while(actuel->fg){
        actuel=actuel->fg;
    }
    return actuel;
}

AVL reequilibrerAVLSup(AVL racine){
    int equilibre = getEquilibre(racine);
    if(equilibre > 1 && getEquilibre(racine->fg) >= 0) return rotationDroite(racine);
    if(equilibre > 1 && getEquilibre(racine->fg) < 0){
        racine->fg = rotationGauche(racine->fg);
        return rotationDroite(racine);
    }
    if(equilibre < -1 && getEquilibre(racine->fd) <= 0) return rotationGauche(racine);
    if(equilibre < -1 && getEquilibre(racine->fd) > 0){
        racine->fd = rotationDroite(racine->fd);
        return rotationGauche(racine);
    }
    return racine;
}

AVL supprimerValeurAVL(AVL racine,int n){
    if(racine==NULL) return racine;

    if(n < racine->val) racine->fg=supprimerValeurAVL(racine->fg,n);

    else if (n > racine->val) racine->fd = supprimerValeurAVL(racine->fd,n);

    else{
        if( (racine->fg==NULL) || (racine->fd==NULL) ){
            AVL temp=racine->fg ? racine->fg : racine->fd;
            if(temp==NULL){
                temp=racine;
                racine=NULL;
            }else *racine=*temp;
            free(temp);
        }else{
             AVL temp = noeudValMin(racine->fd);
             racine->val=temp->val;
             racine->fd=supprimerValeurAVL(racine->fd,temp->val);
        }
    }
    if(racine==NULL) return racine;
    racine->hauteur = 1+max(hauteurAVL(racine->fg),hauteurAVL(racine->fd));
    return reequilibrerAVLSup(racine);
}

void _afficherFormeAVL(AVL a,int niveau){
    if(a) {
        _afficherFormeAVL(a->fd, niveau + 1);
        for (int i = 1; i <= niveau; i++)
            printf("--");
        printf("%d\n", a->val);
        _afficherFormeAVL(a->fg, niveau + 1);
    }
}

void afficherFormeAVL(AVL a){
    _afficherFormeAVL(a,0);
}