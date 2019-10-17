#include "doube_linked_list.h"
#include <stdlib.h>

int dll_create(DoubleLinkedList* ret, 
        Point* p,
        DoubleLinkedList* prev,
        DoubleLinkedList* next){
    ret = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
    if(!ret){
        return 1;
    }
    
    ret->p = p;
    ret->prev = prev;
    ret->next = next;
    return 0;
}

void dll_destroy(DoubleLinkedList* dll){
    DoubleLinkedList* aux, * aux_next;
    if(!dll) return;
    if(dll == dll->next){
        free(dll);
        return;
    }
    for(aux = dll->next, aux_next = dll->next->next; aux_next!=dll; aux_next = aux_next->next){
        free(aux);
        aux = aux_next;
    }
    free(aux);
    free(aux_next);
}

void dll_insert_behind(DoubleLinkedList* dll, Point* p){
    DoubleLinkedList* node;
    dll_create(node, p, dll->prev, dll);
    dll->prev->next = node;
    dll->prev = node;
}

void dll_insert_front(DoubleLinkedList* dll, Point* p){
    dll_insert_behind(dll->next, p);
}

void dll_remove(DoubleLinkedList* dll){
    if(!dll) return;
    if(dll == dll->next){
        free(dll);
        return;
    }
    dll->prev->next = dll->next;
    dll->next->prev = dll->prev;
    free(dll);
}

/*
 * ...             ...
 *  \               /
 *   dll0  ----- dll1   
 * ^ |              | |
 * | ... <-free-> ... |
 * | |              | v
 *   dll0_ ----- dll1_
 *  /                \
 * ...              ...
 */
void dll_join(DoubleLinkedList* dll0,
       DoubleLinkedList* dll0_,
       DoubleLinkedList* dll1, 
       DoubleLinkedList* dll1_){
    if(!dll0)  return;
    if(!dll1)  return;
    if(!dll0_) return;
    if(!dll1_) return;

    // close the loop to destroy safely
    if(dll0 != dll0->prev && dll0->prev != dll0_ && 
            dll0_ != dll0_->next && dll0_->next != dll0){
        DoubleLinkedList* to_free0;
        to_free0 = dll0->prev;

        to_free0->next = dll0_->next;
        to_free0->next->prev = to_free0;

        dll_destroy(to_free0);
    }

    if(dll1 != dll1->next && dll1->next != dll1_ && 
            dll1_ != dll1_->prev && dll1_->prev != dll1){
        DoubleLinkedList* to_free1;
        to_free1 = dll1->next;

        to_free1->prev = dll1_->prev;
        to_free1->prev->next = to_free1;

        dll_destroy(to_free1);
    }
    // connect the ends
    dll0->prev = dll1;
    dll1->next = dll0;

    dll0_->next = dll1_;
    dll1_->prev = dll0_;
}
