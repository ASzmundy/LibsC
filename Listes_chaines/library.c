 #include "library.h"

#include <stdio.h>
#include <stdlib.h>

int estVideS(Listesimple a){
    if (a==NULL) return 1;
    else return 0;
}
int estVideD(Listedouble a){
    if (a.debut==NULL&&a.fin==NULL) return 1;
    else return 0;
}
Listesimple creerListeS(int valeur){
    Listesimple nouveau;
    nouveau = (Listesimple)malloc(sizeof(Cellulesimple));
    nouveau->val=valeur;
    nouveau->suiv=NULL;
    return nouveau;
}
Listedouble creerListeD(int valeur){
     Listedouble nouveau;
     nouveau.debut = (Celluledouble*)malloc(sizeof(Celluledouble));
     nouveau.debut->val=valeur;
     nouveau.debut->suiv=NULL;
     nouveau.debut->prec=NULL;
    nouveau.fin=nouveau.debut;
     return nouveau;
}

Listesimple insererTeteS(Listesimple source,Listesimple destination){
    source->suiv=destination;
    destination=source;
    return destination;
}

Listedouble insererTeteD(Celluledouble *source,Listedouble destination){
     source->suiv=destination.debut;
     destination.debut->prec=source;
     destination.debut=source;
     return destination;
}

Listesimple insererQueueS(Listesimple source, Listesimple destination){
    if(destination==NULL){
        destination=source;
    }
    else{
        destination->suiv= insererQueueS(source,destination->suiv);
    }
    return destination;
}
 Listedouble insererQueueD(Celluledouble *source, Listedouble destination){
    destination.fin->suiv=source;
    source->prec=destination.fin;
    destination.fin=source;
    return destination;
 }

 