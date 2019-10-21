#include "dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>

void print_point(Point p){
    printf("(%d,%d)\n",p[X],p[Y]);
}

void dynamic_array_print(DynamicArray*  v){
    for (int i = 0; i < dynamic_array_size(v); i++)
    {
        Point* Pi = (Point *)v->items[i];
        printf("Array[%d] = ",i);
        print_point(*Pi);
    }
    
    return;
}

int dynamic_array_create(DynamicArray *v) {

    v->capacity = DYNAMIC_ARRAY_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_create ----\n")
        printf("------------------------------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    if(!v->items){
        return 1;
    }

    return 0;
}

int dynamic_array_size(DynamicArray *v) {

    return v->total;
}

int dynamic_array_capacity(DynamicArray *v) {

    return v->capacity;
}

static int dynamic_array_resize(DynamicArray *v, int capacity) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_resize ----\n")
        printf("------------------------------\n");
        printf("DynamicArray_resize: %d to %d\n\n", v->capacity, capacity);

        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }

    if(v->capacity == capacity)
        return 0;

    return 1;
}

int dynamic_array_push(DynamicArray *v, void *item) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_push------\n")
        printf("------------------------------\n\n");
        printf("push");
        print_point(item);
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif

    if (v->capacity == v->total)
        if(v->capacity != 0)
            dynamic_array_resize(v, v->capacity * 2);
        else
            dynamic_array_resize(v, DYNAMIC_ARRAY_INIT_CAPACITY);
    v->items[v->total++] = item;

    #ifdef DEBUG_ON
        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif


    if(v->items[ v->total - 1 ] == item)
        return 0;

    return 1;
}

int dynamic_array_insert(DynamicArray *v, int index, void *item) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_insert-----\n")
        printf("------------------------------\n\n");
        printf("in Array[%d] insert ",index);
        print_point(item);
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif
    /* update */
    if (index >= 0 && index < v->total)
        v->items[index] = item;
    else{
        /* expand */
        if(index > v->capacity){
            dynamic_array_resize(v, index * 2);
        }
        Point aux = {-1,-1};
        for (size_t i = v->total; i < index; i++)
        {
            dynamic_array_push(v,aux);
            //v->items[i] = aux;
        }
        
        v->items[index] = item;
        v->total++;
    }

    #ifdef DEBUG_ON
        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    if(v->items[ index ] == item)
        return 0;

    return 1;
}

void *dynamic_array_get(DynamicArray *v, int index) {

    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

int dynamic_array_delete(DynamicArray *v, int index) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_insert-----\n")
        printf("------------------------------\n\n");
        printf("delete Array[%d]",index);
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif

    int p_total = v->total;

    if (index < 0 || index >= v->total)
        return 1;

    v->items[index] = NULL;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        dynamic_array_resize(v, v->capacity / 2);


    #ifdef DEBUG_ON
        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    if((v->total <  p_total) && (v->items[ index ] == NULL))
        return 0;

    return 1;
}

int dynamic_array_pop(DynamicArray *v) {
    return dynamic_array_delete(v, v->total - 1);
}

int dynamic_array_destroy(DynamicArray *v) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_destroy-----\n")
        printf("------------------------------\n\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif

    free(v->items);
    v->total=0;
    v->capacity=0;

    #ifdef DEBUG_ON
        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %d\n", dynamic_array_size(v));
        printf("Capacity(v) : %d\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    if(v->items == NULL)
        return 0;

    return 1;
}
