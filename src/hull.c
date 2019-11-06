#include "../lib/polygon/polygon.h"
#include "../lib/polygon/polygon.h"
#include "../lib/dynamic_array/dynamic_array.h"
#include "../lib/dynamic_array/merge_sort.h"
#include "../lib/point/point.h"
#include "../lib/line/line.h"
#include <stdlib.h>
#include <stdio.h>

void pprint_pol(Polygon* pol){
    if(!pol) return;

    printf("(%d, %d)", (*pol->p)[X], (*pol->p)[Y]);
    for(Polygon* aux = pol->next; aux->p!=pol->p; aux = aux->next){
        printf("<->(%d, %d)", (*aux->p)[X], (*aux->p)[Y]);
    }
    printf("\n");
}

void print_pol(Polygon* pol){
    if(!pol) return;

    printf("%d %d,%d %d", (*pol->p)[X], (*pol->p)[Y], (*pol->next->p)[X], (*pol->next->p)[Y]);
    for(Polygon* aux = pol->next; aux->p!=pol->p; aux = aux->next){
        printf(";%d %d,%d %d", (*aux->p)[X], (*aux->p)[Y], (*aux->next->p)[X], (*aux->next->p)[Y]);
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
    
    while((line_right_on(l, *(*xl)->prev->p) && (*xl) != (*xl)->prev && !point_is_equal(*(*xl)->p,*(*xl)->prev->p)) || 
            (line_right_on(l, *(*xr)->next->p) && (*xr) != (*xr)->next && !point_is_equal(*(*xr)->p,*(*xr)->next->p))){
        while(line_right_on(l, *(*xl)->prev->p) && (*xl) != (*xl)->prev && !point_is_equal(*(*xl)->p,*(*xl)->prev->p) ){
            (*xl) = (*xl)->prev;
            point_copy(l, *(*xl)->p);
        }
        while(line_right_on(l, *(*xr)->next->p) && (*xr) != (*xr)->next && !point_is_equal(*(*xr)->p,*(*xr)->next->p)){
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
    //printf("\tleft to join: ");
    //print_point(*(*xl)->p);
    //printf("\tright to join: ");
    //print_point(*(*xr)->p);
    
    while((line_left_on(l, *(*xl)->next->p) && (*xl) != (*xl)->next && !point_is_equal(*(*xl)->p,*(*xl)->next->p)) || 
            (line_left_on(l, *(*xr)->prev->p) && (*xr) != (*xr)->prev && !point_is_equal(*(*xr)->p,*(*xr)->prev->p))){
        while(line_left_on(l, *(*xl)->next->p) && (*xl) != (*xl)->next && !point_is_equal(*(*xl)->p,*(*xl)->next->p)){
            //printf("\tadvance in left\n");
            (*xl) = (*xl)->next;
            point_copy(l, *(*xl)->p);
        }
        while(line_left_on(l, *(*xr)->prev->p) && (*xr) != (*xr)->prev && !point_is_equal(*(*xr)->p,*(*xr)->prev->p)){
            //printf("\tadvance in right\n");
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
    Polygon* xll,* xlr,* xrl,* xrr,* xrl_,* xlr_;

    create_hull_aux(&poll, &xll, &xlr, arr, m);
    create_hull_aux(&polr, &xrl, &xrr, arr + m, size - m);

    xlr_ = xlr;
    xrl_ = xrl;
    *xl = xll;
    *xr = xrr;

    Polygon* pol0,* pol0_,* pol1,* pol1_;

    //printf("xlr: ");
    //print_point(*xlr->p);
    //printf("xrl: ");
    //print_point(*xrl->p);
    //printf("xll: ");
    //print_point(*xll->p);
    //printf("xrr: ");
    //print_point(*xrr->p);
    find_lower_lim(&pol0_, &pol1_, &xlr_, &xrl_);
    find_higher_lim(&pol0, &pol1, &xlr, &xrl);
    //printf("lower_lim: (%d, %d) (%d, %d)\n", (*pol0_->p)[X], (*pol0_->p)[Y],
    //                                         (*pol1_->p)[X], (*pol1_->p)[Y]
    //);
    //printf("higherlim: (%d, %d) (%d, %d)\n", (*pol0->p)[X], (*pol0->p)[Y],
    //                                         (*pol1->p)[X], (*pol1->p)[Y]
    //);

    polygon_join(pol0, pol0_, pol1, pol1_);
    //printf("----------");
    //printf("xlr: ");
    //print_point(*xlr->p);
    //printf("xrl: ");
    //print_point(*xrl->p);
    //printf("xll: ");
    //print_point(*xll->p);
    //printf("xrr: ");
    //print_point(*xrr->p);

    *ret = *xl;
    //printf("--left most: ");
    //print_point(*(*xl)->p);
    //printf("--right most: ");
    //print_point(*(*xr)->p);

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
        printf("%d %d\n", (*p_)[X], (*p_)[Y]);
        dynamic_array_push(&d, (void*)p_);
    }
    printf("$\n");
    Polygon* pol;
    create_hull(&pol, &d);

    dynamic_array_destroy(&d);
    polygon_destroy(pol);
    
    return 0;
}
