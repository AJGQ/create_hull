#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"


int main(void)
{
    Point p0 = {1,2}, p1 = {3245,63}, p2 = {-34, 124};
    Point p_0 = {11,232}, p_1 = {-5,2363}, p_2 = {-123, -2907};
    int i;

    DynamicArray v1;
    dynamic_array_create(&v1);
    printf("dynamic_array_create(&v1)\n"); 
    printf("-----------\n");
    dynamic_array_push(&v1, &p0);
    printf("push ");
    print_point(p0);
    printf("\n");

    printf("----- print v1------\n");
    dynamic_array_print(&v1);
    printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    printf("\n");

 
    printf("push ");
    print_point(p1);
    dynamic_array_push(&v1, &p1);
    printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    printf("\n");

    printf("push ");
    print_point(p2);
    dynamic_array_push(&v1, &p2);
    printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    printf("\n");

    printf("push ");
    print_point(p_0);
    dynamic_array_push(&v1, &p_0);
    printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    printf("\n");

    printf("push ");
    print_point(p_1);
    dynamic_array_push(&v1, &p_1);
    printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    printf("\n");

    printf("push ");
    print_point(p_2);
    dynamic_array_push(&v1, &p_2);
    printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    printf("\n");

    printf("-----print v1------\n");
    dynamic_array_print(&v1);
    printf("nº elments(v1) : %d\n", dynamic_array_size(&v1));
    printf("\n");

    printf("pop ");
    print_point(p_2);
    dynamic_array_pop(&v1);
    dynamic_array_print(&v1);
    printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    printf("\n");

    printf("--------\n");
    DynamicArray new = dynamic_array_slice(&v1,2) ;

    dynamic_array_print(&new);
    printf("nº elements(new) : %d\n", dynamic_array_size(&new));
    printf("Capacity(new) : %d\n", dynamic_array_capacity(&new));
    printf("\n");



    //printf("-----destroy---\n");
    //dynamic_array_destroy(&v1);
    //dynamic_array_print(&v1);
    //printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    //printf("Capacity(v1) : %d\n\n", dynamic_array_capacity(&v1));

    //printf("push ");
    //print_point(p1);
    //dynamic_array_push(&v1, &p1);
    //printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    //printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    //printf("\n");

    //printf("push ");
    //print_point(p2);
    //dynamic_array_push(&v1, &p2);
    //printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    //printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    //printf("\n");

    //printf("----- print array ----\n");
    //dynamic_array_print(&v1);
    //printf("nº elements(v1) : %d\n", dynamic_array_size(&v1));
    //printf("Capacity(v1) : %d\n", dynamic_array_capacity(&v1));
    //printf("\n\n");
}
