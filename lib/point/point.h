#ifndef POINT_H
#define POINT_H

#include <stdbool.h> 

#define DIM 2
#define X 0
#define Y 1

typedef int Point[DIM];

void point_create(Point* ret, int x, int y);
bool point_is_equal(Point p0, Point p1);
void point_copy(Point* ret, Point p);

void point_sum(Point* ret, Point p0, Point p1);
void point_difference(Point* ret, Point p0, Point p1);
void point_multiply(Point* ret, int s, Point p);
void point_divide(Point* ret, int s, Point p);

float point_dot_product(Point p0, Point p1);

//float point_magnitude(Point p);
//float point_distance(Point p0, Point p1);

int point_area_sign( Point a, Point b, Point c );

#endif
