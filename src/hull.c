#include "../lib/polygon/polygon.h"
#include "../lib/polygon/polygon.h"
#include "../lib/dynamic_array/dynamic_array.h"
#include "../lib/dynamic_array/merge_sort.h"
#include "../lib/point/point.h"
#include "../lib/line/line.h"
#include <stdlib.h>
#include <stdio.h>

int cmp_x(const Point* a, const Point* b){
    return ((*a)[X] < (*b)[X])? -1: ((*a)[X] > (*b)[X])? 1 : 
        ((*a)[Y] < (*b)[Y])? -1: ((*a)[Y] > (*b)[Y])? 1 : 0;
}


void create_hull(Polygon* ret, DynamicArray* d){
    merge_sort((Point**)d.items, d.total, cmp_x);

    size_t m = d.total/2 + d.total%2;

    //Polygon 
    //create_hull_aux(ret, d);
    //create_hull_aux();
    //...
}

int main(){
    DynamicArray d;
    dynamic_array_create(&d);
    Point p;

    while(scanf("%d %d", p+X, p+Y) == 2){
        Point* p_;
        p_ = (Point*)malloc(sizeof(Point));
        point_copy(p_, p);
        dynamic_array_push(&d, (void*)p_);
    }

    Polygon pol;
    create_hull(&pol, &d);
    
    return 0;
}
