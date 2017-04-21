#include "point.h"

typedef struct PointNode{
    Point point;
    struct PointNode *next;
} PointNode, *PointNodePtr;

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
        return first;
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
void insert_node_middle(Point myPoint, PointNodePtr present){
    PointNodePtr newnode = create_node(myPoint);
    PointNodePtr temp;
    temp = present->next;
    newnode->next = temp;
    present->next = newnode;
}

//Remove Node
void remove_next_node(PointNodePtr present){
    PointNodePtr temp;
    temp = (present->next)->next;
    present->next = temp;
}

//Change Node Value
void change_node_value(Point myPoint, PointNodePtr present){
    present->point = myPoint;
}

//Reset List
void reset_list (PointNodePtr first, PointNodePtr last){
    first = NULL;
    last = NULL;
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

 