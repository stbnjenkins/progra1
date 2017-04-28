#include <stdio.h>
#include <stdlib.h>

#include "texels.c"
#include "plot.c"
#include "Bresenham.c"
#include "Mappings.c"
#include "Clipping.c"
#include "lineNode.c"
#include "Filling.c"
#include "poligon_struct.c"
#include "Movements.c"
#include "poligons_ini.c"
#include "frame_manager.c"
#include "keyboard_input.c"

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

    ini_buffer(res);
    plot_framebuffer(res);

    current_res = res;
    list_of_provinces = create_list_of_provinces();

    frame_plotter (current_res, fill_mode);

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
    openTextureFiles();
    window_runner(res);
}