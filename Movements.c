#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "real_point.h"

#define PI 3.14159265

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

//Function Zoom for real
void r_do_zoom(double Z, int res, Real_PointNodePtr first){
    Real_PointNodePtr ptr;
    Real_Point new_Point;
    double xc,yc;
    xc = yc = (double) res/2;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {   
            new_Point.x = ((ptr->my_Point).x -xc) * Z + xc;
            new_Point.y = ((ptr->my_Point).y -yc) * Z + yc;
            ptr->my_Point = new_Point;
        }
    }
}

//FUnction Zoom for Poligon Colection
void poligon_do_zoom (Poligon_NodePtr first, double Z) {
    Poligon_NodePtr ptr;
    Real_PointNodePtr real_temp;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No Poligons in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {
            real_temp = ptr->list_of_point; 
            r_do_zoom (Z, current_res, real_temp); 
        }
    }
}

//Function rotate for real
void r_do_rotate(double alfa, int res, Real_PointNodePtr first){
    Real_PointNodePtr ptr;
    Real_Point new_Point;
    double value = alfa * (PI / 180.0);
    double des = -1 * ((double) res/2);
    r_do_pan (des,des,first);
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {   
            new_Point.x = (cos(value) * (ptr->my_Point).x) - (sin(value) * (ptr->my_Point).y);
            new_Point.y = (sin(value) * (ptr->my_Point).x) + (cos(value) * (ptr->my_Point).y);
            ptr->my_Point = new_Point;
        }
    }
    des = (double) res/2;
    r_do_pan (des,des,first);
}

//FUnction Rotate for Poligon Colection
void poligon_do_rotate (Poligon_NodePtr first, double alfa) {
    Poligon_NodePtr ptr;
    Real_PointNodePtr real_temp;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No Poligons in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {
            real_temp = ptr->list_of_point; 
            r_do_rotate (alfa, current_res, real_temp); 
        }
    }
}