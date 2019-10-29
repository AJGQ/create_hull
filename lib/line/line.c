#include "line.h"
#include "../point/point.h"

void line_create(Line* ret, Point p0, Point p1){
    point_copy((*ret), p0);
    point_copy((*ret) + 1, p1);
}

int line_left(Line l, Point p){
    return point_area_sign( l[0], l[1], p ) > 0;
}

int line_left_on(Line l, Point p){
    return point_area_sign( l[0], l[1], p ) >= 0;
}

int line_right(Line l, Point p){
    return point_area_sign( l[0], l[1], p ) < 0;
}

int line_right_on(Line l, Point p){
    return point_area_sign( l[0], l[1], p ) <= 0;
}
