#include "remove_repeated.h"

/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
size_t remove_repeated(Point** array, size_t size, 
        int (*cmp)(const Point* a, const Point* b)){
    if(size==0 || size==1) return size;

    size_t j = 0;
    for(size_t i=1; i<size; i++){
        if(cmp(array[j], array[i])){
            array[++j] = array[i];
        }
    }
    return ++j;
}
