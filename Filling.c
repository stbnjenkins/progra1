#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "point.h"

//Get poligon border intersection
Point get_poligon_side_intersection (Point p0, Point p1, int skyline) {
    double m, b, dx, dy;
    Point myPoint;
    dx = (p1.x - p0.x);
    dy = (p1.y - p0.y);
    m = (double) dy / dx;
    b = (double) p0.y - m * p0.x;

    if (m == -INFINITY || m == INFINITY){
        myPoint.x = p0.x;
    } else {
        myPoint.x = round((skyline-b)/m);
    }
    myPoint.y=skyline;
    return myPoint;
}

//Order intersections by x
PointNodePtr sort_intersections (PointNodePtr first){
    PointNodePtr ptr, ptr2, last; 
    Point temp;
    last = NULL;
    if (first == NULL){
    //    printf("\nEMPTY LIST:No nodes in the list to display\n");
    } else{
        for (ptr = first;ptr->next != NULL;ptr = ptr->next){    
            for (ptr2 = first;ptr2->next != last;ptr2 = ptr2->next){
                if ((ptr2->point).x > ((ptr2->next)->point).x){
                    temp = ptr2->point;
                    ptr2->point = (ptr2->next)->point;
                    (ptr2->next)->point = temp;
                }
            }
            last=ptr2;
        }
    }
    return first;
}

//Order points by y
PointNodePtr sort_points_by_y (PointNodePtr first){
    PointNodePtr ptr, ptr2, last; 
    Point temp;
    last = NULL;
    if (first == NULL){
    //    printf("\nEMPTY LIST:No nodes in the list to display\n");
    } else{
        for (ptr = first;ptr->next != NULL;ptr = ptr->next){    
            for (ptr2 = first;ptr2->next != last;ptr2 = ptr2->next){
                if ((ptr2->point).y > ((ptr2->next)->point).y){
                    temp = ptr2->point;
                    ptr2->point = (ptr2->next)->point;
                    (ptr2->next)->point = temp;
                }
            }
            last=ptr2;
        }
    }
    return first;
}

//Map points to poligon borders
LineNodePtr map_points_to_poligon_borders(PointNodePtr first){
    LineNodePtr new_list = line_create_list();
    PointNodePtr ptr;
    if (first == NULL){
    //    printf("\nEMPTY LIST:");
    //    printf(":No nodes in the list to display\n");
    } else{
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next != NULL){
                if ((ptr->point).y < ((ptr->next)->point).y) {
                    new_list = line_insert_node_last(ptr->point,(ptr->next)->point,new_list);
                } else {
                    new_list = line_insert_node_last((ptr->next)->point,ptr->point,new_list);
                }
            } else {
                if ((ptr->point).y < (first->point).y) {
                    new_list = line_insert_node_last(ptr->point,first->point,new_list);
                } else {
                    new_list = line_insert_node_last(first->point,ptr->point,new_list);
                }
            }
        }
    }
    return new_list;
}

//Check Active borders per skyline
LineNodePtr check_active_poligon_borders(LineNodePtr first, int skyline) {
    LineNodePtr new_list = line_create_list();
    LineNodePtr ptr;
    if (first == NULL)     {
    //    printf("\nEMPTY LIST:");
    //    printf(":No nodes in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            if ((ptr->point_ini).y < skyline  && (ptr->point_fin).y > skyline) {
                new_list = line_insert_node_last(ptr->point_ini,ptr->point_fin,new_list);
            }
        }
    }
    return new_list;
}

//Get max/min or knee
PointNodePtr get_max_min_knee (PointNodePtr first, int skyline) {
    PointNodePtr ptr, intersection;
    PointNodePtr pre, actual, post;
    if (first == NULL){
    //    printf("\nEMPTY LIST:");
    //    printf(":No nodes in the list to display\n");
    } else{
        intersection = create_list();
        for (ptr = first;ptr != NULL;ptr = ptr->next){
            pre = ptr;
            if (ptr->next == NULL) {
                actual = first;
            } else {
                actual = (ptr->next);
            }
            if (actual->next == NULL) {
                post = first;
            } else {
                post = (actual->next);
            }

            //cases of max/min knee
            if ((actual->point).y == skyline) {
                if        ((pre->point).y < (actual->point).y && (actual->point).y > (post->point).y) {
                    //Max case
                    intersection = insert_node_last (actual->point, intersection);
                    intersection = insert_node_last (actual->point, intersection);
                } else if ((pre->point).y < (actual->point).y && (actual->point).y < (post->point).y) {
                    //Knee case
                    intersection = insert_node_last (actual->point, intersection);
                } else if ((pre->point).y < (actual->point).y && (actual->point).y == (post->point).y) {
                    //Knee case
                    intersection = insert_node_last (actual->point, intersection);    
                } else if ((pre->point).y > (actual->point).y && (actual->point).y < (post->point).y) {
                    //Min case
                    intersection = insert_node_last (actual->point, intersection);
                    intersection = insert_node_last (actual->point, intersection);
                } else if ((pre->point).y > (actual->point).y && (actual->point).y > (post->point).y) {
                    //Knee case
                    intersection = insert_node_last (actual->point, intersection);
                } else if ((pre->point).y > (actual->point).y && (actual->point).y == (post->point).y) {
                    //Min case
                    intersection = insert_node_last (actual->point, intersection);
                    intersection = insert_node_last (actual->point, intersection);
                } else if ((pre->point).y == (actual->point).y && (actual->point).y > (post->point).y) {
                    //Knee case
                    intersection = insert_node_last (actual->point, intersection);
                 } else if ((pre->point).y == (actual->point).y && (actual->point).y < (post->point).y) {
                    //Min case 
                    intersection = insert_node_last (actual->point, intersection);
                    intersection = insert_node_last (actual->point, intersection);
                 } else if ((pre->point).y == (actual->point).y && (actual->point).y == (post->point).y) {
                    //Max case 
                    intersection = insert_node_last (actual->point, intersection);
                    intersection = insert_node_last (actual->point, intersection);
                }
            }
        }
    }
    return intersection;
}

//Fill skyline
void fill_skyline (PointNodePtr first, double R, double G, double B, int mode) {
    PointNodePtr ptr;
    int pinta = 1;
    if (first == NULL){
    //    printf("\nEMPTY LIST:");
    //    printf(":No nodes in the list to display\n");
    } else if (first->next != NULL){
        for (ptr = first;ptr->next != NULL;ptr = ptr->next) {
            if (pinta == 1) { 
                bresenham(ptr->point,(ptr->next)->point, R, G, B, mode);
                pinta = 0;
            } else {
                pinta = 1;
            }
        }
    }
}

// Filling poligons
void fill_poligon_to_buffer (PointNodePtr first, int yi, int yf, double R, double G, double B, int mode){
    PointNodePtr intersection_list;
    Point temp_point;
    LineNodePtr border_list = map_points_to_poligon_borders(first);
    LineNodePtr active, ptr;
    int skyline;
    for (skyline = yf; skyline >= yi; skyline--) {
        //find max/min or knee
        intersection_list = get_max_min_knee(first, skyline);

        //Check which borders are active
        active = check_active_poligon_borders(border_list, skyline); 

        if (active == NULL) {
        //    printf("\nEMPTY LIST:");
        //    printf(":No nodes in the list to display\n");
        } else {
            for (ptr = active;ptr != NULL;ptr = ptr->next) {    
                temp_point = get_poligon_side_intersection (ptr->point_ini, ptr->point_fin, skyline);
                intersection_list = insert_node_last (temp_point, intersection_list);
            }
        }

        intersection_list = sort_intersections (intersection_list);
        fill_skyline(intersection_list, R, G, B, mode);    
    }
}
