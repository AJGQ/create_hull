#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include "../point/point.h"

typedef struct sDoubleLinkedList {
    Point* p;
    struct sDoubleLinkedList* prev;
    struct sDoubleLinkedList* next;
} DoubleLinkedList;

int dll_create(DoubleLinkedList* ret, 
        Point* p,
        DoubleLinkedList* prev,
        DoubleLinkedList* next);

void dll_destroy(DoubleLinkedList* dll);

void dll_insert_behind(DoubleLinkedList* dll, Point* p);

void dll_insert_front(DoubleLinkedList* dll, Point* p);

void dll_remove(DoubleLinkedList* dll);

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
       DoubleLinkedList* dll1_);

#endif
