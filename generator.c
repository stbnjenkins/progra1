#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "point.h"
#include "line.h"


PointPtr randPointPtr(int res){
    
    // Creating pointer, dont forget to free memory
    PointPtr p = (PointPtr) malloc(sizeof(Point));
    p->x = rand() % res; //random number % res 
    p->y = rand() % res;
    //printf("Point.x -> %d\nPoint.y -> %d\n", p->x, p->y);
    return p;
}

Point randPoint(int res){
    Point p;
    p.x = rand() % res; //random number % res 
    p.y = rand() % res;
    return p;
}

void printLine(LinePtr line){
    printf("P1: %d,%d\n", line->p1->x, line->p1->y);
    printf("P2: %d,%d\n", line->p2->x, line->p2->y);
}

LinePtr randLine(int res){
    LinePtr line  = (LinePtr) malloc(sizeof(Line));
    line->p1 = randPointPtr(res);
    line->p2 = randPointPtr(res);
    printLine(line);
    // liberar p1,p2
    // liberar linea
    return line;
}   

