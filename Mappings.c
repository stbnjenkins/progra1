#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pointNode.c"
#include "RealpointNode.c"


//Map a point into Buffer
void map_point_to_buffer (Real_Point myPoint, int resx, int resy) {
    if (myPoint.x > 0 && myPoint.x < resx && myPoint.y > 0 && myPoint.y < resy) {
        plot(round(myPoint.x),round(myPoint.y), 0, 0, 0, 7);
        plot_framebuffer(resx);
    }
}

//Create poligon using Bresenham
void create_poligon_to_buffer (PointNodePtr first){
    PointNodePtr ptr;
    if (first == NULL){
        //  printf("EMPTY LIST:");
        //  printf(":No nodes in the list to display\n");
    } else{
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next != NULL){
                bresenham(ptr->point,(ptr->next)->point, 0, 0, 0, 7);
            } else {
                bresenham(ptr->point,first->point, 0, 0, 0, 7);
            }
        }
    }
}

//Map Real point list to int point list
PointNodePtr map_real_to_int_point_list (Real_PointNodePtr first) {
    Real_PointNodePtr ptr;
    Point new_point;
    PointNodePtr newlist = create_list();

    if (first == NULL) {
        // printf("\nEMPTY LIST:");
        // printf(":No nodes in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {
            new_point.x = (round((ptr->my_Point).x));
            new_point.y = (round((ptr->my_Point).y));
            newlist = insert_node_last(new_point , newlist);
        }
    }

    return newlist;
}

