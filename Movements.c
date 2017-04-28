#include <stdio.h>
#include <stdlib.h>

#include "real_point.h"

//Function Pan for real
void r_do_pan(double des_x, double des_y, Real_PointNodePtr first){
    Real_PointNodePtr ptr;
    Real_Point new_Point;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {   
            new_Point.x = (ptr->my_Point).x + des_x;
            new_Point.y = (ptr->my_Point).y + des_y;
            ptr->my_Point = new_Point;
        }
    }
}

//FUnction Pan for Poligon Colection
void poligon_do_pan (Poligon_NodePtr first, double des_x, double des_y) {
    Poligon_NodePtr ptr;
    Real_PointNodePtr real_temp;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No Poligons in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {
            real_temp = ptr->list_of_point; 
            r_do_pan (des_x, des_y, real_temp); 
        }
    }
}