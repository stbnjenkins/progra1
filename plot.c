#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int current_res;
COLOR **buffer;

//Plot put the points in the buffer
void plot(int x,int y,double R,double G,double B, int mode){
    if (x<current_res && y <current_res){
        if (mode == 7) {
            buffer[x][y].r = R;
            buffer[x][y].g = G;
            buffer[x][y].b = B;
        } else {
            buffer[x][y] = texel_mapping(x,y, mode);
        }
    }
}

//Take info from buffer and put it on display
void plot_framebuffer(int res) {
  int i, j;
  COLOR color;

  for (i = 0; i < res; i++) 
      {
       for (j = 0; j < res; j++) 
           {
            glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
            glBegin (GL_POINTS);
            glVertex2i (i,j);
            glEnd();
           }
      }
  glFlush();
}

//Initialize buffer (everything white)
void ini_buffer(int res) {
    int i, j;

    //reserve the memory space for the buffer
    buffer = (COLOR **)malloc(res * sizeof(COLOR*));
    for (i = 0; i < res; i++){
        buffer[i] = (COLOR *)malloc(res * sizeof(COLOR));
    }

    //initialize the values R G B for every pixel
    for (i = 0; i < res; i++) {
        for (j = 0; j < res; j++) {
            buffer[i][j].r = 1;
            buffer[i][j].g = 1;
            buffer[i][j].b = 1;
        }
    }
}

