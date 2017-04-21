#include "real_point.h"

typedef struct Real_PointNode{
    Real_Point my_Point;
    struct Real_PointNode *next;
} Real_PointNode, *Real_PointNodePtr;

//Creating Node
Real_PointNodePtr r_create_list(){
    Real_PointNodePtr first;
    first = NULL;
    return first;
}

//Creating Node
Real_PointNodePtr r_create_node(Real_Point myPoint){
    Real_PointNodePtr newnode = (Real_PointNodePtr) malloc(sizeof(Real_PointNode));
    if (newnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    } else {
        newnode->my_Point = myPoint;
        newnode->next = NULL;
        return newnode;
    }
}

//Inserting Node at Last
Real_PointNodePtr r_insert_node_last(Real_Point myPoint, Real_PointNodePtr first){
    Real_PointNodePtr ptr,newnode;  
    newnode = r_create_node(myPoint);
    if (first == NULL) {
        first = newnode;
        first->next = NULL;
    } else {

        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next == NULL){
                ptr->next = newnode;
                newnode->next = NULL;
                return first;
            }
        }
    }
}    

//Insert Node middle
void r_insert_node_middle(Real_Point myPoint, Real_PointNodePtr present){
    Real_PointNodePtr newnode = r_create_node(myPoint);
    Real_PointNodePtr temp;
    temp = present->next;
    newnode->next = temp;
    present->next = newnode;
}

//Remove Node
void r_remove_next_node(Real_PointNodePtr present){
    Real_PointNodePtr temp;
    temp = (present->next)->next;
    present->next = temp;
}

//Change Node Value
void r_change_node_value(Real_Point myPoint, Real_PointNodePtr present){
    present->my_Point = myPoint;
}

//Reset List
Real_PointNodePtr r_reset_list (Real_PointNodePtr first){
    first = NULL;
    return first;
}

//Displays non-empty List from Beginning to End
void r_display(Real_PointNodePtr first) {
    Real_PointNodePtr ptr;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            printf("Point.x -> %lf\nPoint.y -> %lf\n", (ptr->my_Point).x, (ptr->my_Point).y);
        }
    }
}
