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

void find_lower_lim(Polygon** pol0_, Polygon** pol1_, 
        Polygon* pol1, Polygon* pol2,
        Line* l){
    while(line_left(l, )){
        
    }
}

void create_hull_aux(Polygon** ret, Point** arr, size_t size){
    if(size==0) return;
    if(size==1){
        polygon_create(ret, *arr);
        return;
    }
    size_t m = size/2 + size%2;

    Polygon pol1, pol2;
    create_hull_aux(&pol1, arr, m);
    create_hull_aux(&pol2, arr + m, size - m);

    Polygon* pol0, pol0_, pol1, pol1_;
    Line l1, l2;
    line_create(&l1, *(arr[m-1]), *(arr[m]));
    line_create(&l2, *(arr[m-1]), *(arr[m]));

    find_lower_lim(&pol0_, &pol1_, &pol1, &pol2, &l1);
    find_higher_lim(&pol0, &pol1, &pol1, &pol2, &l2);

    polygon_join(pol0, pol0_, pol1, pol1_);
}

void create_hull(Polygon** ret, DynamicArray* d){
    merge_sort((Point**)d.items, d.total, cmp_x);
    create_hull_aux(ret, d.items, d.total);
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

    Polygon* pol;
    create_hull(&pol, &d);
    
    return 0;
}
