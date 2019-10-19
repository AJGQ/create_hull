#include "merge_sort.h"
#include "string.h"

/*
 *  cmp(a,b) == 1  <=> a > b
 *  cmp(a,b) == 0  <=> a == b
 *  cmp(a,b) == -1 <=> a < b
 */
void merge_sort(TYPE* array, size_t size, 
        int (*cmp)(const TYPE* a, const TYPE* b)){

    if(size==0 || size==1) return;

    size_t m = size/2;

    merge_sort(array  , m     , *cmp);
    merge_sort(array+m, size-m, *cmp);
    
    TYPE* aux = (TYPE*)malloc(size*sizeof(TYPE));
    memcpy(aux, array, size*sizeof(TYPE));

    size_t i = 0, j = m, t = 0;
    while(i < m && j < size){
        if(cmp((const TYPE*)aux+i, (const TYPE*)aux+j) < 0)
            array[t++] = aux[i++];
        else
            array[t++] = aux[j++];
    }
    while(i < m)
        array[t++] = aux[i++];
    
    while(j < size)
        array[t++] = aux[j++];
}
