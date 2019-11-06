#include "point.h"
//#include <math.h>

void point_create(Point* ret, int x, int y){
    (*ret)[X] = x;
    (*ret)[Y] = y;
}

bool point_is_equal(Point p0, Point p1){
    return p0[X] == p1[X] && p0[Y] == p1[Y];
}

void point_copy(Point* ret, Point p){
    point_create(ret, p[X], p[Y]);
}

void point_sum(Point* ret, Point p0, Point p1){
    point_create(ret, 
            p0[X] + p1[X],
            p0[Y] + p1[Y]);
}

void point_difference(Point* ret, Point p0, Point p1){
    point_multiply(ret, -1, p1);
    point_sum(ret, p0, *ret);
}

void point_multiply(Point* ret, int s, Point p){
    point_create(ret, 
            s * p[X],
            s * p[Y]);
}

void point_divide(Point* ret, int s, Point p){
    point_create(ret, 
            p[X] / s,
            p[Y] / s);
}

float point_dot_product(Point p0, Point p1){
    return (float)(p0[X] * p1[X] + p0[Y] * p1[Y]);
}

//float point_magnitude(Point p){
//    return (float)sqrt((double)( p[X]*p[X] + p[Y]*p[Y] ));
//}

//float point_distance(Point p0, Point p1){
//    Point aux;
//    point_difference(&aux, p1, p0);
//    return point_magnitude(aux);
//}

int point_area_sign( Point a, Point b, Point c ){
    int area = ( b[0] - a[0] ) * ( c[1] - a[1] ) -
        ( c[0] - a[0] ) * ( b[1] - a[1] );

    if      ( area >  0.5 ) return  1;
    else if ( area < -0.5 ) return -1;
    else                    return  0;
}

