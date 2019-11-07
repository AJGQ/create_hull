#include "merge_sort_diff.h"
#include "string.h"
#include <stdio.h>


/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
size_t merge_sort_diff(Point** array, size_t size, 
        int (*cmp)(const Point* a, const Point* b)){

    //printf("%d:\n", size);
    //for(size_t i = 0; i < size; i++)
    //    printf("(%d,%d) ", (*array[i])[X], (*array[i])[Y]);

    if(size==0 || size==1) return size;

    size_t m = size/2;

    size_t m0 = merge_sort_diff(array  , m     , cmp);
    size_t m1 = merge_sort_diff(array+m, size-m, cmp);
    
    Point** aux = (Point**)malloc(size*sizeof(Point*));
    memcpy(aux, array, size*sizeof(Point*));

    size_t i = 0, j = m0, t = 0;
    size_t size_ = m0 + m1;
    while(i < m0 && j < size_){
        switch(cmp(aux[i], aux[j])){
            case -1:
                array[t++] = aux[i++];
                break;
            case 1:
                array[t++] = aux[j++];
                break;
            default:
                i++;
        }
    }
    while(i < m0)
        array[t++] = aux[i++];
    
    while(j < size_)
        array[t++] = aux[j++];

    free(aux);
    return t;
}
