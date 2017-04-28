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
    // Real_PointNodePtr col3 = r_create_list();

    // Real_Point A;
    // A.x = 200.0; A.y = 355.25;
    // col3 = r_insert_node_last(A, col3);
    // A.x = 100.0; A.y = 100;
    // col3 = r_insert_node_last(A, col3);
    // A.x = 50.0; A.y = 55.25;
    // col3 = r_insert_node_last(A, col3);
    // A.x = 10.0; A.y = 100;
    // col3 = r_insert_node_last(A, col3);

    // PlotPoligon (col3, 0, 0, 200, 200);
    // plot_framebuffer(res);


    PointNodePtr col3 = create_list();

    Point A;
    A.x = 50; A.y = 100;
    col3 = insert_node_last(A, col3);
    A.x = 125; A.y = 300;
    col3 = insert_node_last(A, col3);
    A.x = 25; A.y = 400;
    col3 = insert_node_last(A, col3);
    A.x = 175; A.y = 399;
    col3 = insert_node_last(A, col3);
    A.x = 300; A.y = 500;
    col3 = insert_node_last(A, col3);
    A.x = 425; A.y = 400;
    col3 = insert_node_last(A, col3);
    A.x = 665; A.y = 399;
    col3 = insert_node_last(A, col3);
    A.x = 465; A.y = 300;
    col3 = insert_node_last(A, col3);
    A.x = 550; A.y = 100;
    col3 = insert_node_last(A, col3);
    A.x = 300; A.y = 200;
    col3 = insert_node_last(A, col3);
   
    // A.x = 100; A.y = 100;
    // col3 = insert_node_last(A, col3);
    // A.x = 100; A.y = 500;
    // col3 = insert_node_last(A, col3);
    // A.x = 500; A.y = 500;
    // col3 = insert_node_last(A, col3);
    // A.x = 500; A.y = 100;
    // col3 = insert_node_last(A, col3);
    
    create_poligon_to_buffer(col3);
    PointNodePtr tu = get_max_min_knee (col3, 100) ;
    display(tu);
    fill_poligon_to_buffer (col3, 1, 800, 1, 0.5, 0.5);
    
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