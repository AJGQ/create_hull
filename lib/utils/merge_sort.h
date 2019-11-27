#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>
#include "../point/point.h"

/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
void merge_sort(Point** array, size_t size, 
        int (*cmp)(const Point* a, const Point* b));
#endif
