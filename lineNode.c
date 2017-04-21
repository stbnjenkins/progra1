#include "point.h"

typedef struct LineNode{
    Point point_ini;
    Point point_fin;
    struct LineNode *next;
} LineNode, *LineNodePtr;


LineNodePtr lnewnode, lptr;
LineNodePtr lfirst = NULL, llast = NULL;

/*
 * Creating Node
 */

LineNodePtr line_create_node(Point myPoint_ini,Point myPoint_fin){
    lnewnode = (LineNodePtr) malloc(sizeof(LineNode));
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

/*
 * Inserting Node at Last
 */

void line_insert_node_last(Point myPoint_ini,Point myPoint_fin){
    lnewnode = line_create_node(myPoint_ini, myPoint_fin);
    if (lfirst == llast && llast == NULL)
    {
        lfirst = llast = lnewnode;
        lfirst->next = NULL;
        llast->next = NULL;
    }
    else
    {
        llast->next = lnewnode;
        llast = lnewnode;
        llast->next = NULL;
    }
}    

/*
 * Displays non-empty List from Beginning to End
 */

void line_display()
{
    if (lfirst == NULL)
    {
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    }
    else
    {
        for (lptr = lfirst;lptr != NULL;lptr = lptr->next)
        {    
            printf("Point1.x -> %d\nPoint1.y -> %d\nPoint2.x -> %d\nPoint2.y -> %d\n", (lptr->point_ini).x, (lptr->point_ini).y, (lptr->point_fin).x, (lptr->point_fin).y);
        }
    }
}

 