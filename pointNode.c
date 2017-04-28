#include "point.h"

typedef struct PointNode{
    Point point;
    struct PointNode *next;
    struct PointNode *list_next;
} PointNode, *PointNodePtr;

PointNodePtr first_node = NULL, last_node = NULL;
int cont;
// Creating List
PointNodePtr create_list(){
    PointNodePtr first;
    first = NULL;
    return first;
}

// Creating Node
PointNodePtr create_node(Point myPoint){
    PointNodePtr newnode = (PointNodePtr) malloc(sizeof(PointNode));
    if (newnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    } else {
        newnode->point = myPoint;
        newnode->next = NULL;
        return newnode;
    }
}

//Inserting Node at Last
 PointNodePtr insert_node_last(Point myPoint, PointNodePtr first){
    PointNodePtr ptr, newnode;
    newnode = create_node(myPoint);

    if (first == NULL) {
        first = newnode;
        first->next = NULL;
//Complete list 
        if (first_node == last_node && last_node == NULL) {
            first_node = last_node = newnode;
            first_node->list_next = NULL;
            last_node->list_next = NULL;
        } else {
            last_node->list_next = newnode;
            last_node = newnode;
            last_node->list_next = NULL;
        }
//
        return first;
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            if (ptr->next == NULL){
                ptr->next = newnode;
                newnode->next = NULL;
//Complete list 
                last_node->list_next = newnode;
                last_node = newnode;
                last_node->list_next = NULL;
//                    
                return first;
            }
        }
    }
}    

// Displays non-empty List from Beginning to End
void display(PointNodePtr first){
    PointNodePtr ptr;
    if (first == NULL){
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    } else{
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            printf("Point.x -> %d\nPoint.y -> %d\n", (ptr->point).x, (ptr->point).y);
        }
    }
}

// Displays non-empty List from Beginning to End
void total_display(PointNodePtr first){
    cont = 0;
    PointNodePtr ptr;
    if (first == NULL){
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    } else{
        for (ptr = first;ptr != NULL;ptr = ptr->list_next){    
            cont++;
            printf("Point.x -> %d\nPoint.y -> %d\n", (ptr->point).x, (ptr->point).y);
        }
    }
    printf("cont -> %d\n", cont);
}

// Release Memory
void point_list_delete () {
    PointNodePtr ptr;
    if (first_node == NULL){
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to remove\n");
    } else{
        while (first_node != NULL) {
            ptr = first_node;
            first_node = ptr->list_next;
            free(ptr);
        }
    }
}

 