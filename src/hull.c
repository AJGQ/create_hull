#include "../lib/polygon/polygon.h"
#include "../lib/polygon/polygon.h"
#include "../lib/dynamic_array/dynamic_array.h"
#include "../lib/utils/merge_sort.h"
#include "../lib/utils/remove_repeated.h"
#include "../lib/utils/print.h"
#include "../lib/point/point.h"
#include "../lib/line/line.h"
#include <stdlib.h>
#include <stdio.h>

bool pretty;

int cmp_x(const Point* a, const Point* b){
    return ((*a)[X] < (*b)[X])? -1: ((*a)[X] > (*b)[X])? 1 : 
        ((*a)[Y] < (*b)[Y])? -1: ((*a)[Y] > (*b)[Y])? 1 : 0;
}

void find_lower_lim(Polygon** pol0_, Polygon** pol1_, 
        Polygon* xll, Polygon* xrr,
        Polygon* xlr, Polygon* xrl){
    if(!xlr || !xrl) return;

    Line l;
    line_create(&l, *xlr->p, *xrl->p);
    bool left_lim = (xlr == xll), 
         right_lim = (xrl == xrr);
    
    while((line_right_on(l, *xlr->prev->p) && !left_lim) || 
            (line_right_on(l, *xrl->next->p) && !right_lim)){
        while(line_right_on(l, *xlr->prev->p) && !left_lim){
            xlr = xlr->prev;
            point_copy(l, *xlr->p);
            if(xlr == xll){
                left_lim = true;
            }
        }
        while(line_right_on(l, *xrl->next->p) && !right_lim){
            xrl = xrl->next;
            point_copy(l+1, *xrl->p);
            if(xrl == xrr){
                right_lim = true;
            }
        }
    }
    *pol0_ = xlr;
    *pol1_ = xrl;
}

void find_higher_lim(Polygon** pol0, Polygon** pol1, 
        Polygon* xll, Polygon* xrr,
        Polygon* xlr, Polygon* xrl){
    if(!xlr || !xrl) return;

    Line l;
    line_create(&l, *xlr->p, *xrl->p);
    bool left_lim = (xlr == xll), 
         right_lim = (xrl == xrr);
    
    while((line_left_on(l, *xlr->next->p) && !left_lim) || 
            (line_left_on(l, *xrl->prev->p) && !right_lim)){
        while(line_left_on(l, *xlr->next->p) && !left_lim){
            xlr = xlr->next;
            point_copy(l, *xlr->p);
            if(xlr == xll){
                left_lim = true;
            }
        }
        while(line_left_on(l, *xrl->prev->p) && !right_lim){
            xrl = xrl->prev;
            point_copy(l+1, *xrl->p);
            if(xrl == xrr){
                right_lim = true;
            }
        }
    }
    *pol0 = xlr;
    *pol1 = xrl;
}

void create_hull_aux(Polygon** ret, 
        Polygon** xl, Polygon** xr,
        Point** arr, size_t size){
    if(size==0) return;
    if(size==1){
        polygon_create(ret, *arr);

        *xl = *ret;
        *xr = *ret;

        if(!pretty)
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

    find_lower_lim(&pol0_, &pol1_, xll, xrr, xlr, xrl);
    find_higher_lim(&pol0, &pol1, xll, xrr, xlr, xrl);

    polygon_join(pol0, pol0_, pol1, pol1_);

    *ret = *xl;

    if(!pretty)
        print_pol(*ret);    
}

void create_hull(Polygon** ret, DynamicArray* d){
    merge_sort((Point**)d->items, d->total, cmp_x);
    size_t size = remove_repeated((Point**)d->items, d->total, cmp_x);
    d->total = size;
    dynamic_array_resize(d, size);
    Polygon* xl,* xr;
    create_hull_aux(ret, &xl, &xr, (Point**)d->items, d->total);
}

int main(int argc, char** argv){
    pretty = !(argc==2 && argv[1][0]=='c');
    DynamicArray d;
    dynamic_array_create(&d);
    Point p;
    size_t points = 0;

    while(scanf("%d %d", p+X, p+Y) == 2){
        Point* p_;
        p_ = (Point*)malloc(sizeof(Point));
        point_copy(p_, p);
        if(!pretty)
            printf("%d %d\n", (*p_)[X], (*p_)[Y]);
        dynamic_array_push(&d, (void*)p_);
        points++;
    }
    if(!pretty)
        printf("$\n");
    Polygon* pol;

    create_hull(&pol, &d);
    if(pretty)
        pprint_pol(pol);

    dynamic_array_destroy(&d);
    polygon_destroy(pol);
    return 0;
}
