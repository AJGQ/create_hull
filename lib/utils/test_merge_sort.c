#include "merge_sort.h"
#include <stdio.h>

int compare_int(const int* a, const int* b){
    return *a > *b ? 1 : (*a < *b? -1 : 0);
}

void print_array(int* arr, size_t size){
    for(unsigned i =0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int* arr0;
    int arr1[1] = {2};
    int arr2[15] = {2,31,54,765,2,5,7,2,4,6,7,2,4556,3234,3};
    
    printf("sort ");
    print_array(arr0, 0);
    merge_sort(arr0, 0, *compare_int);
    print_array(arr0, 0);
    
    printf("sort ");
    print_array(arr1, 1);
    merge_sort(arr1, 1, *compare_int);
    print_array(arr1, 1);
    
    printf("sort ");
    print_array(arr2, 15);
    merge_sort(arr2, 15, *compare_int);
    print_array(arr2, 15);
    
    return 0;
}
