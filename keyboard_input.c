enum Draw_Mode {
    LINE_MODE,
    COLOR_MODE,
    TEXEL_MODE
};

int fill_mode = LINE_MODE;
int current_res;

void setMode(int newMode){
    fill_mode = newMode;
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
            list_of_provinces = create_list_of_provinces();
            ini_buffer(current_res);
            plot_framebuffer(current_res);
            frame_plotter (current_res, 0);
            return;
        case 88: // X
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Zoom in con shift\n");
                return;
            }
            printf("Zoom in\n");
            return;
        case 90: // Z
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Zoom out con shift\n");
                return;
            }
            printf("Zoom out\n");
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
            list_of_provinces = create_list_of_provinces();
            ini_buffer(current_res);
            plot_framebuffer(current_res);
            frame_plotter (current_res, 0);
            return;        
        case 120: // x
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Zoom in con shift\n");
                return;
            }
            printf("Zoom in\n");
            return;
        case 122: // z
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                printf("Zoom out con shift\n");
                return;
            }
            printf("Zoom out\n");
            return;
    }
}
// rotacion, pan y zoom
void processSpecialKeys(int key, int x, int y) {
    int mod = glutGetModifiers();
	switch(key) {
		case GLUT_KEY_F1 :
                setMode(LINE_MODE);
                printf("%d\n", fill_mode);
                frame_plotter (current_res, fill_mode);
				return;
		case GLUT_KEY_F2 :
                setMode(COLOR_MODE);
				printf("%d\n", fill_mode);
                frame_plotter (current_res, fill_mode);
				return;
		case GLUT_KEY_F3 :
                setMode(TEXEL_MODE);
				printf("%d\n", fill_mode);
                frame_plotter (current_res, fill_mode);
				return;
        case GLUT_KEY_LEFT :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan left con shift\n");
                    poligon_do_pan (list_of_provinces, -30, 0);
                    frame_plotter (current_res, fill_mode);
                    return;
                }
				printf("Pan left\n");
                poligon_do_pan (list_of_provinces, -10, 0);
                frame_plotter (current_res, fill_mode);
				return;
        case GLUT_KEY_RIGHT :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan right con shift\n");
                    poligon_do_pan (list_of_provinces, 30, 0);
                    frame_plotter (current_res, fill_mode);
                    return;
                }
				printf("Pan right\n");
                poligon_do_pan (list_of_provinces, 10, 0);
                frame_plotter (current_res, fill_mode);
				return;
        case GLUT_KEY_DOWN :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan down con shift\n");
                    poligon_do_pan (list_of_provinces, 0, -30);
                    frame_plotter (current_res, fill_mode);
                    return;
                }
				printf("Pan down\n");
                poligon_do_pan (list_of_provinces, 0, -10);
                frame_plotter (current_res, fill_mode);
				return;
        case GLUT_KEY_UP :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    printf("Pan up con shift\n");
                    poligon_do_pan (list_of_provinces, 0, 30);
                    frame_plotter (current_res, fill_mode);
                    return;
                }
				printf("Pan up\n");
                poligon_do_pan (list_of_provinces, 0, 10);
                frame_plotter (current_res, fill_mode);
				return;
	}
}
