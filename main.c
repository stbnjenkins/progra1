#include <stdio.h>
#include <stdlib.h>

#include "plot.c"
#include "Bresenham.c"
#include "Mappings.c"
#include "Movements.c"
#include "Clipping.c"
#include "PlotPoligons.c"


//Run the window
void window_runner(int res) {
    //starting window
    char *myargv[1];
    int myargc=1;
    myargv [0]=strdup ("Plot");
    glutInit(&myargc, myargv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(res,res);
    glutCreateWindow("Plot");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, res +0.5, -0.5, res + 0.5);

//Mayor Funct to be called here
    Real_PointNodePtr col3 = r_create_list();

    Real_Point A;
    A.x = 200.0; A.y = 355.25;
    col3 = r_insert_node_last(A, col3);
    A.x = 100.0; A.y = 100;
    col3 = r_insert_node_last(A, col3);
    A.x = 50.0; A.y = 55.25;
    col3 = r_insert_node_last(A, col3);
    A.x = 10.0; A.y = 100;
    col3 = r_insert_node_last(A, col3);

    PlotPoligon (col3, 0, 0, 200, 200);
    plot_framebuffer(res);

//  glutDisplayFunc(dummy);
    glutMainLoop();
}

int main(int argc, char **argv){
    int res; 

    // get parameters
    if (argc != 2) {
        printf("Usage <program> <resolution>\n");
        return -1;
    }  


    // Get parameters
    res = (int) atoi(argv[1]);
//    n_lines = (int) atoi(argv[2]);
//    times = (int) atoi(argv[3]);
//    doplot = (int) atoi(argv[4]);

    //initialzing buffer
    ini_buffer(res);

    //Executing Window
    window_runner(res);
}