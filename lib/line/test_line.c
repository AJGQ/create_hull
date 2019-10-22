#include "line.h"
#include <stdio.h>

int main(){

    Point p0 = {0,0}, p1 = {1,0}, p2 = {1,1};
    
    Line l;
    line_create(&l, p0, p2);


    printf("%d\n", line_left(l, p1));

    return 0;
}
