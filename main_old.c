#include <stdio.h>
#include <stdlib.h>

#include "plot.c"
#include "Bresenham.c"
#include "Mappings.c"
#include "Movements.c"
#include "Clipping.c"
#include "PlotPoligons.c"
#include "lineNode.c"
#include "Filling.c"
#include "keyboard_input.c"
#include "RealPointNode.c"

//initialize the first get_poligon 
Real_PointNodePtr first_poligon () {    
    RealPointNodePtr col3 = r_create_list();

    Real_Point A;
    A.x = 50.1; A.y = 100.4;
    col3 = insert_node_last(A, col3);
    A.x = 125.2; A.y = 300.4;
    col3 = insert_node_last(A, col3);
    A.x = 25.0; A.y = 400.3;
    col3 = insert_node_last(A, col3);
    A.x = 175.6; A.y = 399.7;
    col3 = insert_node_last(A, col3);
    A.x = 300.9; A.y = 500.8;
    col3 = insert_node_last(A, col3);
    A.x = 425.8; A.y = 400.9;
    col3 = insert_node_last(A, col3);
    A.x = 665.7; A.y = 399.1;
    col3 = insert_node_last(A, col3);
    A.x = 465.6; A.y = 300.1;
    col3 = insert_node_last(A, col3);
    A.x = 550.4; A.y = 100.0;
    col3 = insert_node_last(A, col3);
    A.x = 300.3; A.y = 200.2;
    col3 = insert_node_last(A, col3);

    return col3;
}

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

    // here are the new entries
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

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
    Point p0, p1, p2, p3, p4, data;
    p0.x=0;p0.y=0;
    p1.x=5;p1.y=0;
//    data = get_poligon_side_intersection (p0, p1, 10);

    PointNodePtr col3 = create_list();

    Point A;
    A.x = 200; A.y = 1;
    col3 = insert_node_last(A, col3);
    A.x = 100; A.y = 20;
    col3 = insert_node_last(A, col3);
    A.x = 50; A.y = 15;
    col3 = insert_node_last(A, col3);
    A.x = 10; A.y = 4;
    col3 = insert_node_last(A, col3);

 //   col3 = sort_intersections (col3);
 //   display(col3);
    PointNodePtr tu = get_max_min_knee (col3, 4) ;

    LineNodePtr my = map_points_to_poligon_borders(col3);
    display(tu);
    printf("other\n");
    LineNodePtr other = check_active_poligon_borders(my, 15);
    line_display(other);
    //Executing Window
    window_runner(res);
}