#ifndef MERGE_SORT_DIFF_H
#define MERGE_SORT_DIFF_H

#include <stdlib.h>
#include "../point/point.h"

/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
size_t merge_sort_diff(Point** array, size_t size, 
        int (*cmp)(const Point* a, const Point* b));
#endif
