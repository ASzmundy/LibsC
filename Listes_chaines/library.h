#ifndef LISTES_CHAINES_LIBRARY_H
#define LISTES_CHAINES_LIBRARY_H
typedef struct _cell1{
    int val;
    struct _cell1 *suiv;
}Cellulesimple, *Listesimple;
typedef struct _cell2{
    int val;
    struct _cell2 *suiv,*prec;
}Celluledouble;
typedef struct{
    Celluledouble *debut, *fin;
}Listedouble;

int estVideS(Listesimple a);
int estVideD(Listedouble a);
Listesimple creerListeS(int valeur);
Listedouble creerListeD(int valeur);
Listesimple insererTeteS(Listesimple source,Listesimple destination);
Listedouble insererTeteD(Celluledouble *source,Listedouble destination);
Listesimple insererQueueS(Listesimple source, Listesimple destination);
Listedouble insererQueueD(Celluledouble *source, Listedouble destination);


#endif //LISTES_CHAINES_LIBRARY_H
