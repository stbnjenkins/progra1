#include "real_point.h"

typedef struct Real_PointNode{
    Real_Point my_Point;
    struct Real_PointNode *next;
    struct Real_PointNode *list_next;
} Real_PointNode, *Real_PointNodePtr;

Real_PointNodePtr r_first_node = NULL, r_last_node = NULL;
int r_cont;

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
 //Complete list 
        if (r_first_node == r_last_node && r_last_node == NULL) {
            r_first_node = r_last_node = newnode;
            r_first_node->list_next = NULL;
            r_last_node->list_next = NULL;
        } else {
            r_last_node->list_next = newnode;
            r_last_node = newnode;
            r_last_node->list_next = NULL;
        }
//       
        return first;
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next == NULL){
                ptr->next = newnode;
                newnode->next = NULL;
//Complete list 
                r_last_node->list_next = newnode;
                r_last_node = newnode;
                r_last_node->list_next = NULL;
//   
                return first;
            }
        }
    }
}  

//Inserting Node at Last
Real_PointNodePtr r_insert_node_last_pro(Real_Point myPoint, Real_PointNodePtr first){
    Real_PointNodePtr ptr,newnode;  
    newnode = r_create_node(myPoint);

    if (first == NULL) {
        first = newnode;
        first->next = NULL;
        first->list_next = NULL;
        return first;
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next == NULL){
                ptr->next = newnode;
                newnode->next = NULL;
                newnode->list_next = NULL;
                return first;
            }
        }
    }
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

// Displays non-empty List from Beginning to End
void r_total_display(Real_PointNodePtr first) {
    r_cont = 0;
    Real_PointNodePtr ptr;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->list_next) { 
            r_cont++;   
            printf("Point.x -> %lf\nPoint.y -> %lf\n", (ptr->my_Point).x, (ptr->my_Point).y);
        }
    }
    printf("cont -> %d\n", r_cont);
}

// Release Memory
void r_point_list_delete () {
    Real_PointNodePtr ptr;
    if (r_first_node == NULL){
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to remove\n");
    } else{
        while (r_first_node != NULL) {
            ptr = r_first_node;
            r_first_node = ptr->list_next;
            free(ptr);
        }
    }
}