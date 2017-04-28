#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "helpers.c"

void bresenham(Point p0, Point p1, double R, double G, double B) {

    // trivial case p0 = p1
    if(p0.x == p1.x && p0.y == p1.y){
        plot(p0.x, p0.y, R, G, B);
        //printf("(%d, %d)", p0.x, p0.y);
        return;
    }

    /* If x component in both points is the same,
    then make sure p0 is the one with lower y 
    component. Otherwise, if p0.x is greater than
    p1.x, swap them.
    */
    if(p0.x == p1.x){
        if(p0.y > p1.y) swapPoints(&p0, &p1);
    }else{
        if(p0.x > p1.x) swapPoints(&p0, &p1);
    }

    //printf("Point.x -> %d\nPoint.y -> %d\n", p0.x, p0.y);
    //printf("Point.x -> %d\nPoint.y -> %d\n", p1.x, p1.y);

    //Initial Vars
    int Delta_E, Delta_NE, Delta_SE, Delta_N, Delta_S; 
    int d, xp, yp, i, xdif, ydif;
    xp = p0.x; yp = p0.y;
    xdif = p1.x-p0.x; ydif = p1.y-p0.y;

    //Common Delta
    Delta_N = -xdif-xdif;
    Delta_E = ydif+ydif;
    Delta_S = xdif+xdif;
    Delta_NE = ydif-xdif+ydif-xdif;
    Delta_SE = ydif+xdif+ydif+xdif;

    //print first point
    plot(xp, yp, R, G, B);
   // printf("(%d, %d)", xp, yp);


    //Calculing cases
    if(ydif >= 0) {
        if(ydif >= xdif) {
            //cuadrante 2
            d = ydif-xdif-xdif;
            
            //ciclo
            for(i = p0.y; i < p1.y; i++){
                if (d<0){
                    plot(xp+1, yp+1, R, G, B);
                //    printf("(%d, %d)", xp+1, yp+1);
                    xp++; yp++; d = d + Delta_NE;
                } else{
                    plot(xp, yp+1, R, G, B);
               //     printf("(%d, %d)", xp, yp+1);

                    yp++; d = d + Delta_N;
                }
            }
        } else {
            //cuadrante 1
            d = ydif+ydif-xdif;

            //ciclo
            for(i = p0.x; i < p1.x; i++){
                if (d<0){
                    plot(xp+1, yp, R, G, B);
                //    printf("(%d, %d)", xp+1, yp);
                    xp++; d = d + Delta_E;
                } else{
                    plot(xp+1, yp+1, R, G, B);
                 //   printf("(%d, %d)", xp+1, yp+1);
                    xp++; yp++; d = d + Delta_NE;
                }
            }
        }
    } else {
        if(-ydif >= xdif) {
            //cuadrante 7
            d = ydif+xdif+xdif;

            //ciclo
            for(i = p0.y; i > p1.y; i--){
                if (d<0){
                    plot(xp, yp-1, R, G, B);
                //    printf("(%d, %d)", xp, yp-1);
                    yp--; d = d + Delta_S;
                } else{
                    plot(xp+1, yp-1, R, G, B);
                //    printf("(%d, %d)", xp+1, yp-1);
                    xp++; yp--; d = d + Delta_SE;
                }
            }
        } else {
            //cuadrante 8
            d = ydif+ydif+xdif;

            //ciclo
            for(i = p0.x; i < p1.x; i++){
                if (d<0){
                    plot(xp+1, yp-1, R , G, B);
                //    printf("(%d, %d)", xp+1, yp-1);
                    xp++; yp--; d = d + Delta_SE;
                } else{
                    plot(xp+1, yp, R, G, B);
               //     printf("(%d, %d)", xp+1, yp);
                    xp++; d = d + Delta_E;
                }
            }
        }
    }
}

