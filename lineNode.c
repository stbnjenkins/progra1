#include "point.h"

typedef struct LineNode{
    Point point_ini;
    Point point_fin;
    struct LineNode *next;
} LineNode, *LineNodePtr;

// Creating Node

// Creating List
LineNodePtr line_create_list(){
    LineNodePtr first;
    first = NULL;
    return first;
}

LineNodePtr line_create_node(Point myPoint_ini,Point myPoint_fin){
    LineNodePtr lnewnode = (LineNodePtr) malloc(sizeof(LineNode));
    if (lnewnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    }
    else {
        lnewnode->point_ini = myPoint_ini;
        lnewnode->point_fin = myPoint_fin;
        lnewnode->next = NULL;
        return lnewnode;
    }
}

// Inserting Node at Last
LineNodePtr line_insert_node_last(Point myPoint_ini,Point myPoint_fin, LineNodePtr first){
    LineNodePtr lnewnode, ptr;
    lnewnode = line_create_node(myPoint_ini, myPoint_fin);
    if (first == NULL) {
        first = lnewnode;
        first->next = NULL;
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next == NULL){
                ptr->next = lnewnode;
                lnewnode->next = NULL;
                return first;
            }
        }
    }
}    

//Displays non-empty List from Beginning to End
void line_display(LineNodePtr first) {
    LineNodePtr ptr;
    if (first == NULL)     {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            printf("Point1.x -> %d\nPoint1.y -> %d\nPoint2.x -> %d\nPoint2.y -> %d\n", (ptr->point_ini).x, (ptr->point_ini).y, (ptr->point_fin).x, (ptr->point_fin).y);
        }
    }
}

 