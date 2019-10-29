#include "polygon.h"
#include <stdio.h>

void print_pol(Polygon* pol){
    if(!pol) return;

    printf("(%d, %d)", (*pol->p)[X], (*pol->p)[Y]);
    for(Polygon* aux = pol->next; aux!=pol; aux = aux->next){
        printf("<->(%d, %d)", (*aux->p)[X], (*aux->p)[Y]);
    }
    printf("\n");
}

int main(){
    Point p0 = {1,2}, p1 = {3245,63}, p2 = {-34, 124};
    Point p_0 = {11,232}, p_1 = {-5,2363}, p_2 = {-123, -2907};
    Polygon* pol;
    Polygon* pol_;


    polygon_create(&pol, &p0);
    printf("polygon_create(&pol, &p0) :\n");
    print_pol(pol);

    polygon_insert_behind(pol, &p1);
    printf("polygon_insert_behind(pol, &p1) :\n");
    print_pol(pol);
    
    polygon_insert_front(pol, &point_O);
    printf("polygon_insert_front(pol, &point_O) :\n");
    print_pol(pol);

    polygon_remove(pol->next);
    printf("polygon_remove(pol->next) :\n");
    print_pol(pol);

    polygon_insert_front(pol, &p2);
    printf("polygon_insert_front(pol, &p2) :\n");
    print_pol(pol);

    polygon_create(&pol_, &p_0);
    polygon_insert_front(pol_, &p_1);
    polygon_insert_front(pol_, &p_2);
    printf("pol_ :\n");
    print_pol(pol_);

    polygon_join(pol->next, pol, pol_, pol_->next->next);
    printf("polygon_join(pol->next, pol, pol_, pol_->next->next) :\n");
    print_pol(pol);

    polygon_destroy(pol);
    
    /*----------------------------*/

    printf("\n------------------------\n");




    return 0;
}
