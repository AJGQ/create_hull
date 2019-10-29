#include "dynamic_array.h"

#include <stdio.h>

void print_point(Point p){
    printf("(%d,%d)\n",p[X],p[Y]);
}

void dynamic_array_print(DynamicArray*  v){
    for (size_t i = 0; i < dynamic_array_size(v); i++)
    {
        Point* Pi = (Point *)v->items[i];
        printf("Array[%ld] = ",i);
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
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    if(!v->items){
        return 1;
    }

    return 0;
}

DynamicArray dynamic_array_slice(DynamicArray *v , size_t index ){
    DynamicArray ret;
    dynamic_array_create(&ret);

    for (size_t i = index; i < v->total; i++)
    {
        dynamic_array_push(&ret,v->items[i]);
    }

    return ret;
}

size_t dynamic_array_size(DynamicArray *v) {

    return v->total;
}

size_t dynamic_array_capacity(DynamicArray *v) {

    return v->capacity;
}

static int dynamic_array_resize(DynamicArray *v, size_t capacity) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_resize ----\n")
        printf("------------------------------\n");
        printf("DynamicArray_resize: %ld to %ld\n\n", v->capacity, capacity);

        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
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
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif

    if (v->capacity == v->total){
        if(v->capacity != 0)
            dynamic_array_resize(v, v->capacity * 2);
        else
            dynamic_array_resize(v, DYNAMIC_ARRAY_INIT_CAPACITY);
    }
    v->items[v->total++] = item;

    #ifdef DEBUG_ON
        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif


    if(v->items[ v->total - 1 ] == item)
        return 0;

    return 1;
}

int dynamic_array_insert(DynamicArray *v, size_t index, void *item) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_insert-----\n")
        printf("------------------------------\n\n");
        printf("in Array[%ld] insert ",index);
        print_point(item);
        dynamic_array_print(&v);
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif
    /* update */
    if (index < v->total)
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
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    if(v->items[ index ] == item)
        return 0;

    return 1;
}

void *dynamic_array_get(DynamicArray *v, size_t index) {

    if (index < v->total)
        return v->items[index];
    return NULL;
}

int dynamic_array_delete(DynamicArray *v, size_t index) {

    #ifdef DEBUG_ON
        printf("------------------------------\n");
        printf("---- dynamic_array_insert-----\n")
        printf("------------------------------\n\n");
        printf("delete Array[%ld]",index);
        dynamic_array_print(&v);
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif

    size_t p_total = v->total;

    if (index >= v->total)
        return 1;

    v->items[index] = NULL;

    for (size_t i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        dynamic_array_resize(v, v->capacity / 2);


    #ifdef DEBUG_ON
        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
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
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("\n\n");
    #endif

    free(v->items);
    v->total=0;
    v->capacity=0;

    #ifdef DEBUG_ON
        printf("----- print array------\n");
        dynamic_array_print(&v);
        printf("nº elements(v) : %ld\n", dynamic_array_size(v));
        printf("Capacity(v) : %ld\n", dynamic_array_capacity(v));
        printf("______________________________\n");
        printf("\n");
    #endif

    if(v->items == NULL)
        return 0;

    return 1;
}
