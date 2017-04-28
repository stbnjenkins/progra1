#include <stdio.h>
#include <stdlib.h>

#include "point.h"
#include "real_point.h"

//Take Real Poligon and plot on buffer
void PlotPoligon (Real_PointNodePtr first, int xi, int yi, int xf, int yf){
    PointNodePtr int_point_list;
    Real_PointNodePtr newlist;
 
    newlist = clipping (first, xi , yi, xf, yf);
    int_point_list = map_real_to_int_point_list(newlist);
    create_poligon_to_buffer(int_point_list);
}

//Take Poligon and filled on buffer
void FillPoligon (){
    
}
