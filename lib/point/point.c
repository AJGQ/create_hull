#include "point.h"
#include <math.h>

void point_create(Point* ret, int x, int y){
    (*ret)[X] = x;
    (*ret)[Y] = y;
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

float point_magnitude(Point p){
    return (float)sqrt((double)( p[X]*p[X] + p[Y]*p[Y] ));
}

float point_distance(Point p0, Point p1){
    Point aux;
    point_difference(&aux, p1, p0);
    return point_magnitude(aux);
}

