#include "print.h"

void pprint_pol(Polygon* pol){
    if(!pol) return;

    printf("(%d, %d)", (*pol->p)[X], (*pol->p)[Y]);
    for(Polygon* aux = pol->next; aux->p!=pol->p; aux = aux->next){
        printf("<->(%d, %d)", (*aux->p)[X], (*aux->p)[Y]);
    }
    printf("\n");
}

void print_pol(Polygon* pol){
    if(!pol) return;

    printf("%d %d,%d %d", (*pol->p)[X], (*pol->p)[Y], (*pol->next->p)[X], (*pol->next->p)[Y]);
    for(Polygon* aux = pol->next; aux->p!=pol->p; aux = aux->next){
        printf(";%d %d,%d %d", (*aux->p)[X], (*aux->p)[Y], (*aux->next->p)[X], (*aux->next->p)[Y]);
    }
    printf("\n");
}


