#include "polygon.h"
#include <stdlib.h>

int polygon_create(Polygon** ret, Point* p){
    *ret = (Polygon*) malloc(sizeof(Polygon));
    if(!*ret){
        return 1;
    }
    Polygon* aux = *ret;
    
    aux->p = p;
    aux->prev = aux;
    aux->next = aux;
    return 0;
}

void polygon_destroy(Polygon* pol){
    Polygon* aux, * aux_next;
    if(!pol) return;
    if(pol == pol->next){
        free(pol);
        return;
    }
    for(aux = pol->next, aux_next = pol->next->next; aux_next!=pol; aux_next = aux_next->next){
        free(aux);
        aux = aux_next;
    }
    free(aux);
    free(aux_next);
}

void polygon_insert_behind(Polygon* pol, Point* p){
    Polygon* node;
    Polygon* prev = pol->prev;

    polygon_create(&node, p);
    pol->prev->next = node;
    pol->prev = node;
    node->next = pol;
    node->prev = prev;
}

void polygon_insert_front(Polygon* pol, Point* p){
    polygon_insert_behind(pol->next, p);
}

void polygon_remove(Polygon* pol){
    if(!pol) return;
    if(pol == pol->next){
        free(pol);
        return;
    }
    pol->prev->next = pol->next;
    pol->next->prev = pol->prev;
    free(pol);
}

/*
 * ...             ...
 *  \               /
 *   pol0  ----- pol1   
 * ^ |              | |
 * | ... <-free-> ... |
 * | |              | v
 *   pol0_ ----- pol1_
 *  /                \
 * ...              ...
 */
void polygon_join(Polygon* pol0,
       Polygon* pol0_,
       Polygon* pol1, 
       Polygon* pol1_){
    if(!pol0)  return;
    if(!pol1)  return;
    if(!pol0_) return;
    if(!pol1_) return;

    // close the loop to destroy safely
    if(pol0 != pol0->prev && pol0->prev != pol0_ && 
            pol0_ != pol0_->next && pol0_->next != pol0){
        Polygon* to_free0;
        to_free0 = pol0->prev;

        to_free0->next = pol0_->next;
        to_free0->next->prev = to_free0;

        polygon_destroy(to_free0);
    }

    if(pol1 != pol1->next && pol1->next != pol1_ && 
            pol1_ != pol1_->prev && pol1_->prev != pol1){
        Polygon* to_free1;
        to_free1 = pol1->next;

        to_free1->prev = pol1_->prev;
        to_free1->prev->next = to_free1;

        polygon_destroy(to_free1);
    }

    // connect the ends
    pol0->prev = pol1;
    pol1->next = pol0;

    pol0_->next = pol1_;
    pol1_->prev = pol0_;
}
