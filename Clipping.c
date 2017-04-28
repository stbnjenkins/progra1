#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//criteria comparizon for clipping
int criteria_comparizon (double value_ini, double value_fin, int border, int criteria) {
//criteria 0 -> right or top -> max
    if (criteria == 0){
        if (value_ini <= border) {
            if (value_fin <= border){
                //case ALFA
                return 0;
            } else {
                //case BETA
                return 1;
            }
        } else {
            if (value_fin <= border){
                //case DELTA
                return 2;
            } else {
                //case GAMA
                return 3;
            }
        }
//criteria 1 -> left or buttom -> min        
    } else {
        if (value_ini >= border) {
            if (value_fin >= border){
                //case ALFA
                return 0;
            } else {
                //case BETA
                return 1;
            }
        } else {
            if (value_fin >= border){
                //case DELTA
                return 2;
            } else {
                //case GAMA
                return 3;
            }
        }  
    }
} 

//Get Border intersection
Real_Point get_border_intersection (Real_Point p0, Real_Point p1, int border, int criteria){
    double m, b, dx, dy;
    Real_Point myPoint;
    dx = (p1.x - p0.x);
    dy = (p1.y - p0.y);
    m = (double) dy / dx;
    b = (double) p0.y - m * p0.x;

//criteria 0 -> border is on x
    if (criteria == 0){
        myPoint.x = border;
        if (m == -INFINITY || m == INFINITY){
            myPoint.y = p0.y;
        } else {
            myPoint.y = border*m + b;
        }
    }
//criteria 1 -> border is on y
    else {
        myPoint.y = border;
        if (m == -INFINITY || m == INFINITY){
            myPoint.x = p0.x;
        } else {
            myPoint.x = (border-b)/m;
        }
    }
    return myPoint;
}

//Border comparizon for clipping
Real_PointNodePtr clipping (Real_PointNodePtr first, int xi, int yi, int resx, int resy) {
    Real_PointNodePtr newlist, ptr, temp;
    Real_Point next_Point;
//    newlist = r_create_list();
    int mycase;

    if (first == NULL) {
        printf("\nEMPTY LIST No nodes in the list to display\n");
    } else {

//For x max BORDER
        temp = r_create_list();
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            if (ptr->next == NULL){next_Point = first->my_Point;} else {next_Point = (ptr->next)->my_Point;}
            mycase = criteria_comparizon ((ptr->my_Point).x, next_Point.x, resx, 0);
            
            if (mycase == 0) {//case ALFA
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 1) {//case BETA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, resx, 0), temp);
            } else if (mycase == 2) {//case DELTA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, resx, 0), temp);
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 3) {//case GAMMA

            } 
        }
        newlist = temp;

//For x min BORDER
        temp = r_create_list();
        for (ptr = newlist;ptr != NULL;ptr = ptr->next) {    
            if (ptr->next == NULL){next_Point = newlist->my_Point;} else {next_Point = (ptr->next)->my_Point;}
            mycase = criteria_comparizon ((ptr->my_Point).x, next_Point.x, xi, 1);
            
            if (mycase == 0) {//case ALFA
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 1) {//case BETA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, xi, 0), temp);
            } else if (mycase == 2) {//case DELTA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, xi, 0), temp);
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 3) {//case GAMMA

            } 
        }
        newlist = temp;

//For y max BORDER
        temp = r_create_list();
        for (ptr = newlist;ptr != NULL;ptr = ptr->next) {    
            if (ptr->next == NULL){next_Point = newlist->my_Point;} else {next_Point = (ptr->next)->my_Point;}
            mycase = criteria_comparizon ((ptr->my_Point).y, next_Point.y, resy, 0);
            
            if (mycase == 0) {//case ALFA
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 1) {//case BETA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, resy, 1), temp);
            } else if (mycase == 2) {//case DELTA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, resy, 1), temp);
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 3) {//case GAMMA

            } 
        }
        newlist = temp;
//For y min BORDER
        temp = r_create_list();
        for (ptr = newlist;ptr != NULL;ptr = ptr->next) {    
            if (ptr->next == NULL){next_Point = newlist->my_Point;} else {next_Point = (ptr->next)->my_Point;}
            mycase = criteria_comparizon ((ptr->my_Point).y, next_Point.y, yi, 1);
            
            if (mycase == 0) {//case ALFA
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 1) {//case BETA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, yi, 1), temp);
            } else if (mycase == 2) {//case DELTA
                temp = r_insert_node_last(get_border_intersection (ptr->my_Point, next_Point, yi, 1), temp);
                temp = r_insert_node_last(next_Point, temp);
            } else if (mycase == 3) {//case GAMMA

            } 
        }
        newlist = temp;
    }
//End
    return newlist;
}

