#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>

#define TYPE int

/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
void merge_sort(TYPE* array, size_t size, 
        int (*cmp)(const TYPE* a, const TYPE* b));
#endif
