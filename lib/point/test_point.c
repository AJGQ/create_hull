#include "point.h"
#include <stdio.h>

void print_point(Point p){
    printf("(%d, %d)\n", p[X], p[Y]);
}

int main(){
    Point p0, p1, ret;

    // create
    point_create(&p0, 4, 1);
    printf("point_create(&p0, 4, 1) : ");
    print_point(p0);

    point_create(&p1, 2, 5);
    printf("point_create(&p1, 2, 5) : ");
    print_point(p1);

    // sum
    point_sum(&ret, p0, p1);
    printf("point_sum(&ret, p0, p1) : ");
    print_point(ret);

    // difference
    point_difference(&ret, p0, p1);
    printf("point_difference(&ret, p0, p1) : ");
    print_point(ret);

    point_difference(&ret, p1, p0);
    printf("point_difference(&ret, p1, p0) : ");
    print_point(ret);

    // multiply
    point_multiply(&ret, 20, p0);
    printf("point_multiply(&ret, 20, p0) : ");
    print_point(ret);

    point_multiply(&ret,-123, p1);
    printf("point_multiply(&ret,-123, p1) : ");
    print_point(ret);

    // divide
    point_divide(&ret, 2, p0);
    printf("point_divide(&ret, 2, p0) : ");
    print_point(ret);

    point_divide(&ret,-3, p1);
    printf("point_divide(&ret,-3, p1) : ");
    print_point(ret);

    // dot_product
    float f = point_dot_product(p0, p1);
    printf("point_dot_product(p0, p1) : %g\n", f);

    // magnitude
    f = point_magnitude(p0);
    printf("point_magnitude(p0) : %g\n", f);

    f = point_magnitude(p1);
    printf("point_magnitude(p1) : %g\n", f);

    // distance
    f = point_distance(p0, p1);
    printf("point_distance(p0, p1) : %g\n", f);

    return 0;
}
