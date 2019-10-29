#ifndef POLYGON_H
#define POLYGON_H

#include "../point/point.h"

typedef struct sPolygon{
    Point* p;
    struct sPolygon* prev;
    struct sPolygon* next;
} Polygon;

int polygon_create(Polygon** ret, 
        Point* p);

void polygon_copy(Polygon* ret, Polygon pol);

void polygon_destroy(Polygon* pol);

void polygon_insert_behind(Polygon* pol, Point* p);

void polygon_insert_front(Polygon* pol, Point* p);

void polygon_remove(Polygon* pol);

/*
 * ...             ...
 *  \               /
 *   pol0  ----- pol1   
 * ^ |              | |
 * | ... <-free-> ... |
 * | |              | v
 *   pol0_ ----- pol1_
 *  /                \
 * ...              ...
 */
void polygon_join(Polygon* pol0,
       Polygon* pol0_,
       Polygon* pol1, 
       Polygon* pol1_);

#endif
