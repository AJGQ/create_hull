#include <stdio.h>
#include <stdlib.h>
#include "../point/point.h"
#include "remove_repeated.h"
#include "merge_sort.h"

int cmp(const Point* a, const Point* b){
    return (*a)[X] < (*b)[X] ? -1 : 
        (*a)[X] > (*b)[X] ?  1 :
        (*a)[Y] < (*b)[Y] ? -1 :
        (*a)[Y] > (*b)[Y] ?  1 : 0;
}

void print_array(Point** array, size_t size){
    for(size_t i = 0; i<size; i++){
        printf("(%d, %d) ", (*(array[i]))[X], (*(array[i]))[Y]);
    }
    printf("\n");
}

int main(){
    size_t sz = 10;
    size_t new_sz;
    Point** arr = (Point**)malloc(sz*sizeof(Point*));
    for(unsigned i=0; i<sz; i++){
        arr[i] = (Point*)malloc(sizeof(Point));
        (*(arr[i]))[X] = i;
        (*(arr[i]))[Y] = i;
    }
    merge_sort(arr, sz, cmp);
    print_array(arr, sz);
    new_sz = remove_repeated(arr, sz, cmp);
    print_array(arr, new_sz);
    for(unsigned i=0; i<sz; i++){
        free(arr[i]);
    }
    free(arr);

    sz = 10;
    arr = (Point**)malloc(sz*sizeof(Point*));
    for(unsigned i=0; i<sz; i++){
        arr[i] = (Point*)malloc(sizeof(Point));
        (*(arr[i]))[X] = i%7;
        (*(arr[i]))[Y] = i%7;
    }
    merge_sort(arr, sz, cmp);
    print_array(arr, sz);
    new_sz = remove_repeated(arr, sz, cmp);
    print_array(arr, new_sz);
    for(unsigned i=0; i<sz; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}
