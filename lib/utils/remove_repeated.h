#ifndef REMOVE_REPEATED_H
#define REMOVE_REPEATED_H

#include <stdlib.h>
#include "../point/point.h"

/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
/*
 *  this just works on sorted lists
 */
size_t remove_repeated(Point** array, size_t size, 
        int (*cmp)(const Point* a, const Point* b));
#endif
