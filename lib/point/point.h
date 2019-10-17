#ifndef POINT
#define POINT

#define DIM 2
#define X 0
#define Y 1

typedef int Point[DIM];
static Point point_O = {0, 0};

void point_create(Point* ret, int x, int y);

void point_sum(Point* ret, Point p0, Point p1);
void point_difference(Point* ret, Point p0, Point p1);
void point_multiply(Point* ret, int s, Point p);
void point_divide(Point* ret, int s, Point p);

float point_dot_product(Point p0, Point p1);

float point_magnitude(Point p);
float point_distance(Point p0, Point p1);

#endif
