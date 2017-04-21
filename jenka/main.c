#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();

	glFlush();
}

void processNormalKeys(unsigned char key, int x, int y) {
    int mod = glutGetModifiers();
	switch(key){
        case 27: //escape
            exit(0);
        case 74: // J
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Rotar manecillas reloj con shift\n");
                return;
            }
            printf("Rotar manecillas reloj\n");
            return;
        case 75: // K
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Rotar contrario manecillas reloj con shift\n");
                return;
            }
            printf("Rotar contrario manecillas reloj\n");
            return;
        case 81: // Q
            exit(0);
        case 82: // R
            printf("Reiniciar\n");
            return;
        case 106: // j
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Rotar manecillas reloj con shift\n");
                return;
            }
            printf("Rotar manecillas reloj\n");
            return;
        case 107: // k
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Rotar contrario manecillas reloj con shift\n");
                return;
            }
            printf("Rotar contrario manecillas reloj\n");
            return;
        case 113: // q
            exit(0);
        case 114: // r
            printf("Reiniciar\n");
            return;        
    }
}
// rotacion, pan y zoom
void processSpecialKeys(int key, int x, int y) {
    int mod = glutGetModifiers();
	switch(key) {
		case GLUT_KEY_F1 :
				printf("Sin colorear\n");
				return;
		case GLUT_KEY_F2 :
				printf("Coloreado\n");
				return;
		case GLUT_KEY_F3 : //GLUT_KEY_DOWN
				printf("Con texturas\n");
				return;
        case GLUT_KEY_LEFT :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan left con shift\n");
                    return;
                }
				printf("Pan left\n");
				return;
        case GLUT_KEY_RIGHT :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan right con shift\n");
                    return;
                }
				printf("Pan right\n");
				return;
        case GLUT_KEY_DOWN :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan down con shift\n");
                    return;
                }
				printf("Pan down\n");
				return;
        case GLUT_KEY_UP :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan up con shift\n");
                    return;
                }
				printf("Pan up\n");
				return;
	}
}



int main(int argc, char **argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(530,483);
	int windowID = glutCreateWindow("Progra super pichuda");

    // register callbacks
	glutDisplayFunc(renderScene);

    // here are the new entries
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;

}