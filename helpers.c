#ifndef HELPERS
#define HELPERS

#include "point.h"
// function to swap values of points
void swapPoints(PointPtr p0, PointPtr p1){
    Point temp = *p0;
    *p0 = *p1;
    *p1 = temp;
}

#endif /* HELPERS */

