#include "../point/point.h"

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define DYNAMIC_ARRAY_INIT_CAPACITY 4

#define DYNAMIC_ARRAY_INIT(vec) vector vec; vector_init(&vec)
#define DYNAMIC_ARRAY_ADD(vec, item) vector_add(&vec, (void *) item)
#define DYNAMIC_ARRAY_SET(vec, id, item) vector_set(&vec, id, (void *) item)
#define DYNAMIC_ARRAY_GET(vec, type, id) (type) vector_get(&vec, id)
#define DYNAMIC_ARRAY_DELETE(vec, id) vector_delete(&vec, id)
#define DYNAMIC_ARRAY_TOTAL(vec) vector_total(&vec)
#define DYNAMIC_ARRAY_FREE(vec) vector_free(&vec)

typedef struct DynamicArray {
    void **items;
    int capacity;
    int total;
} DynamicArray;

int dynamic_array_create(DynamicArray *);
DynamicArray dynamic_array_slice(DynamicArray * , int );
int dynamic_array_size(DynamicArray *);
int dynamic_array_capacity(DynamicArray *);
static int dynamic_array_resize(DynamicArray *, int);
int dynamic_array_push(DynamicArray *, void *);
int dynamic_array_insert(DynamicArray *, int, void *);
void *dynamic_array_get(DynamicArray *, int);
int dynamic_array_delete(DynamicArray *, int);
int dynamic_array_pop(DynamicArray *);
int dynamic_array_destroy(DynamicArray *);
//void dynamic_array_print(DynamicArray *);

void print_point(Point);
void dynamic_array_print(DynamicArray* );

#endif