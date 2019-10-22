#include "merge_sort.h"
#include "string.h"
#include <stdio.h>


/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
void merge_sort(Point** array, size_t size, 
        int (*cmp)(const Point* a, const Point* b)){

    //printf("%d:\n", size);
    //for(size_t i = 0; i < size; i++)
    //    printf("(%d,%d) ", (*array[i])[X], (*array[i])[Y]);

    if(size==0 || size==1) return;

    size_t m = size/2;

    merge_sort(array  , m     , cmp);
    merge_sort(array+m, size-m, cmp);
    
    Point** aux = (Point**)malloc(size*sizeof(Point*));
    memcpy(aux, array, size*sizeof(Point*));

    size_t i = 0, j = m, t = 0;
    while(i < m && j < size){
        if(cmp(aux[i], aux[j]) < 0)
            array[t++] = aux[i++];
        else
            array[t++] = aux[j++];
    }
    while(i < m)
        array[t++] = aux[i++];
    
    while(j < size)
        array[t++] = aux[j++];

    free(aux);
}
