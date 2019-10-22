#ifndef LINE_H
#define LINE_H
#include "../point/point.h"

typedef Point Line[2];

void line_create(Line* ret, Point p0, Point p1);
int line_left(Line l, Point p);

#endif
