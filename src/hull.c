#include "../lib/polygon/polygon.h"
#include "../lib/polygon/polygon.h"
#include "../lib/dynamic_array/dynamic_array.h"
#include "../lib/dynamic_array/merge_sort.h"
#include "../lib/point/point.h"
#include "../lib/line/line.h"
#include <stdlib.h>
#include <stdio.h>

void print_pol(Polygon* pol){
    if(!pol) return;

    printf("(%d, %d)", (*pol->p)[X], (*pol->p)[Y]);
    for(Polygon* aux = pol->next; aux->p!=pol->p; aux = aux->next){
        printf("<->(%d, %d)", (*aux->p)[X], (*aux->p)[Y]);
    }
    printf("\n");
}

int cmp_x(const Point* a, const Point* b){
    return ((*a)[X] < (*b)[X])? -1: ((*a)[X] > (*b)[X])? 1 : 
        ((*a)[Y] < (*b)[Y])? -1: ((*a)[Y] > (*b)[Y])? 1 : 0;
}

void find_lower_lim(Polygon** pol0_, Polygon** pol1_, 
        Polygon** xl, Polygon** xr){
    if(!(*xl) || !(*xr)) return;

    Line l;
    line_create(&l, *(*xl)->p, *(*xr)->p);
    
    while((line_right_on(l, *(*xl)->prev->p) && (*xl) != (*xl)->prev) || 
            (line_right_on(l, *(*xr)->next->p) && (*xr) != (*xr)->next)){
        while(line_right_on(l, *(*xl)->prev->p) && (*xl) != (*xl)->prev ){
            (*xl) = (*xl)->prev;
            point_copy(l, *(*xl)->p);
        }
        while(line_right_on(l, *(*xr)->next->p) && (*xr) != (*xr)->next ){
            (*xr) = (*xr)->next;
            point_copy(l+1, *(*xr)->p);
        }
    }
    *pol0_ = (*xl);
    *pol1_ = (*xr);
}

void find_higher_lim(Polygon** pol0, Polygon** pol1, 
        Polygon** xl, Polygon** xr){
    if(!(*xl) || !(*xr)) return;

    Line l;
    line_create(&l, *(*xl)->p, *(*xr)->p);
    
    while((line_left_on(l, *(*xl)->next->p) && (*xl) != (*xl)->next ) || 
            (line_left_on(l, *(*xr)->prev->p) && (*xr) != (*xr)->prev )){
        while(line_left_on(l, *(*xl)->next->p) && (*xl) != (*xl)->next ){
            (*xl) = (*xl)->next;
            point_copy(l, *(*xl)->p);
        }
        while(line_left_on(l, *(*xr)->prev->p) && (*xr) != (*xr)->prev ){
            (*xr) = (*xr)->prev;
            point_copy(l+1, *(*xr)->p);
        }
    }
    *pol0 = (*xl);
    *pol1 = (*xr);
}

void create_hull_aux(Polygon** ret, 
        Polygon** xl, Polygon** xr,
        Point** arr, size_t size){
    if(size==0) return;
    if(size==1){
        polygon_create(ret, *arr);

        *xl = *ret;
        *xr = *ret;

        print_pol(*ret);    
        return;
    }
    size_t m = size/2 + size%2;

    Polygon* poll,* polr;
    Polygon* xll,* xlr,* xrl,* xrr;

    create_hull_aux(&poll, &xll, &xlr, arr, m);
    create_hull_aux(&polr, &xrl, &xrr, arr + m, size - m);

    *xl = xll;
    *xr = xrr;

    Polygon* pol0,* pol0_,* pol1,* pol1_;

    find_lower_lim(&pol0_, &pol1_, &xlr, &xrl);
    find_higher_lim(&pol0, &pol1, &xlr, &xrl);

    polygon_join(pol0, pol0_, pol1, pol1_);

    *ret = *xl;
    print_pol(*ret);    
}

void create_hull(Polygon** ret, DynamicArray* d){
    merge_sort((Point**)d->items, d->total, cmp_x);
    Polygon* xl,* xr;
    create_hull_aux(ret, &xl, &xr, (Point**)d->items, d->total);
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

    dynamic_array_destroy(&d);
    polygon_destroy(pol);
    
    return 0;
}
