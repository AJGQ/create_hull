#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"

void print_point(Point p){
    printf("(%d,%d)\n",p[X],p[Y]);
}

void dynamic_array_print(DynamicArray*  v){
    for (int i = 0; i < dynamic_array_size(v); i++)
    {
        Point* Pi = (Point *)v->items[i];
        printf("Array[%d] = ",i);
        print_point(*Pi);
    }
    
    return;
}


int main(void)
{
    Point p0 = {1,2}, p1 = {3245,63}, p2 = {-34, 124};
    Point p_0 = {11,232}, p_1 = {-5,2363}, p_2 = {-123, -2907};
    int i;

    DynamicArray v1;
    dynamic_array_create(&v1);
    printf("dynamic_array_create(&v1)\n"); 
    dynamic_array_push(&v1, &p0);
    print_point(p0);
    dynamic_array_print(&v1);
    printf("Capacity(v1) : %d\n", dynamic_array_size(&v1));
 
    dynamic_array_push(&v1, &p1);
    dynamic_array_push(&v1, &p2);
    dynamic_array_push(&v1, &p_0);
    dynamic_array_push(&v1, &p_1);
    dynamic_array_push(&v1, &p_2);

    printf("-----------\n");
    dynamic_array_print(&v1);
    printf("Capacity(v1) : %d\n", dynamic_array_size(&v1));

    dynamic_array_pop(&v1);
    dynamic_array_print(&v1);
    printf("Capacity(v1) : %d\n", dynamic_array_size(&v1));

    //DynamicArray v;
    //dynamic_array_create(&v);

    //dynamic_array_push(&v, "Bonjour");
    //dynamic_array_push(&v, "tout");
    //dynamic_array_push(&v, "le");
    //dynamic_array_push(&v, "monde");

    //for (i = 0; i < dynamic_array_size(&v); i++)
    //    printf("%s ", (char *) dynamic_array_get(&v, i));
    //printf("\n");

    //dynamic_array_delete(&v, 3);
    //dynamic_array_delete(&v, 2);
    //dynamic_array_delete(&v, 1);

    //dynamic_array_insert(&v, 0, "Hello");
    //dynamic_array_push(&v, "World");

    //for (i = 0; i < dynamic_array_size(&v); i++)
    //    printf("%s ", (char *) dynamic_array_get(&v, i));
    //printf("\n");

    //dynamic_array_destroy(&v);
}
