#include "dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>


void dynamic_array_create(DynamicArray *v) {

    v->capacity = DYNAMIC_ARRAY_INIT_CAPACITY;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
}

int dynamic_array_size(DynamicArray *v) {

    return v->total;
}

int dynamic_array_capacity(DynamicArray *v) {

    return v->capacity;
}

static void dynamic_array_resize(DynamicArray *v, int capacity) {

    #ifdef DEBUG_ON
    printf("DynamicArray_resize: %d to %d\n", v->capacity, capacity);
    #endif

    void **items = realloc(v->items, sizeof(void *) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void dynamic_array_push(DynamicArray *v, void *item) {

    if (v->capacity == v->total)
        dynamic_array_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void dynamic_array_insert(DynamicArray *v, int index, void *item) {

    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

void *dynamic_array_get(DynamicArray *v, int index) {

    if (index >= 0 && index < v->total)
        return v->items[index];
    return NULL;
}

void dynamic_array_delete(DynamicArray *v, int index) {

    if (index < 0 || index >= v->total)
        return;

    v->items[index] = NULL;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        dynamic_array_resize(v, v->capacity / 2);
}

void dynamic_array_pop(DynamicArray *v) {
    dynamic_array_delete(v, v->total - 1);
}

void dynamic_array_destroy(DynamicArray *v) {
    free(v->items);
}
