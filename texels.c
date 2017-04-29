#include <stdlib.h>
#include <stdio.h>
#include "rgb.h"

#define SWAP(x) ( ((x) << 24) | \
         (((x) << 8) & 0x00ff0000) | \
         (((x) >> 8) & 0x0000ff00) | \
         ((x) >> 24) )
#define FIX(x) (*(unsigned *)&(x) = \
         SWAP(*(unsigned *)&(x)))

enum Provincias {
    SAN_JOSE,
    CARTAGO,
    ALAJUELA,
    PUNTARENAS,
    LIMON,
    HEREDIA,
    GUANACASTE
};

FILE    *fptr_alajuela, 
        *fptr_cartago,
        *fptr_guanacaste,
        *fptr_limon,
        *fptr_puntarenas,
        *fptr_san_jose,
        *fptr_heredia;

COLOR  **texture_alajuela,
        **texture_san_jose,
        **texture_heredia,
        **texture_limon,
        **texture_guanacaste,
        **texture_puntarenas,
        **texture_cartago;

int width_alajuela,height_alajuela,
    width_cartago,height_cartago,
    width_guanacaste,height_guanacaste,
    width_limon,height_limon,
    width_puntarenas,height_puntarenas,
    width_san_jose,height_san_jose,
    width_heredia,height_heredia;


void openTextureFiles(){
    int a,r,g,b;
    // Alajuela
    if ((fptr_alajuela = fopen("textures/alajuela.avs","rb")) == NULL) {
      fprintf(stderr,"Failed to open alajuela input file\n");
      exit(-1);
    }
    
    /* Get width */
    fread(&width_alajuela,sizeof(int),1,fptr_alajuela);
    width_alajuela = FIX(width_alajuela);
    /* Get height */
    fread(&height_alajuela,sizeof(int),1,fptr_alajuela);
    height_alajuela = FIX(height_alajuela);

    int i, j;
    texture_alajuela = (COLOR **)malloc(width_alajuela * sizeof(COLOR*));
    for (i = 0; i < width_alajuela; i++) {
        texture_alajuela[i] = (COLOR *)malloc(height_alajuela * sizeof(COLOR));
    }

    // Rellenar matriz
    
    i = 0;
    j = 0;
    COLOR t;
    while(i < width_alajuela){
        while(j < height_alajuela){
            a = fgetc(fptr_alajuela);   //alfa
            r = fgetc(fptr_alajuela);   // red
            g = fgetc(fptr_alajuela);   // green
            b = fgetc(fptr_alajuela);   // blue
            t.r = r/255.0;
            t.g = g/255.0;
            t.b = b/255.0;
            texture_alajuela[i][j] = t;
            j++;
        }
        j = 0;
        i++;
    }
    fclose(fptr_alajuela);

    // SAN JOSE
    if ((fptr_san_jose = fopen("textures/san_jose.avs","rb")) == NULL) {
      fprintf(stderr,"Failed to open SAN_JOSE input file\n");
      exit(-1);
    }
    
    /* Get width */
    fread(&width_san_jose,sizeof(int),1,fptr_san_jose);
    width_san_jose = FIX(width_san_jose);
    /* Get height */
    fread(&height_san_jose,sizeof(int),1,fptr_san_jose);
    height_san_jose = FIX(height_san_jose);

    texture_san_jose = (COLOR **)malloc(width_san_jose * sizeof(COLOR*));
    for (i = 0; i < width_san_jose; i++) {
        texture_san_jose[i] = (COLOR *)malloc(height_san_jose * sizeof(COLOR));
    }

    i = 0;
    j = 0;
    while(i < width_san_jose){
        while(j < height_san_jose){
            a = fgetc(fptr_san_jose);   //alfa
            r = fgetc(fptr_san_jose);   // red
            g = fgetc(fptr_san_jose);   // green
            b = fgetc(fptr_san_jose);   // blue
            t.r = r/255.0;
            t.g = g/255.0;
            t.b = b/255.0;
            texture_san_jose[i][j] = t;
            j++;
        }
        j = 0;
        i++;
    }
    fclose(fptr_san_jose);

    // HEREDIA
    if ((fptr_heredia = fopen("textures/mmora.avs","rb")) == NULL) {
      fprintf(stderr,"Failed to open HEREDIA input file\n");
      exit(-1);
    }
    
    /* Get width */
    fread(&width_heredia,sizeof(int),1,fptr_heredia);
    width_heredia = FIX(width_heredia);
    /* Get height */
    fread(&height_heredia,sizeof(int),1,fptr_heredia);
    height_heredia = FIX(height_heredia);

    texture_heredia = (COLOR **)malloc(width_heredia * sizeof(COLOR*));
    for (i = 0; i < width_heredia; i++) {
        texture_heredia[i] = (COLOR *)malloc(height_heredia * sizeof(COLOR));
    }

    i = 0;
    j = 0;
    while(i < width_heredia){
        while(j < height_heredia){
            a = fgetc(fptr_heredia);   //alfa
            r = fgetc(fptr_heredia);   // red
            g = fgetc(fptr_heredia);   // green
            b = fgetc(fptr_heredia);   // blue
            t.r = r/255.0;
            t.g = g/255.0;
            t.b = b/255.0;
            texture_heredia[i][j] = t;
            j++;
        }
        j = 0;
        i++;
    }
    fclose(fptr_heredia);

    // CARTAGO
    if ((fptr_cartago = fopen("textures/cartago.avs","rb")) == NULL) {
      fprintf(stderr,"Failed to open CARTAGO input file\n");
      exit(-1);
    }
    
    /* Get width */
    fread(&width_cartago,sizeof(int),1,fptr_cartago);
    width_cartago = FIX(width_cartago);
    /* Get height */
    fread(&height_cartago,sizeof(int),1,fptr_cartago);
    height_cartago = FIX(height_cartago);

    texture_cartago = (COLOR **)malloc(width_cartago * sizeof(COLOR*));
    for (i = 0; i < width_cartago; i++) {
        texture_cartago[i] = (COLOR *)malloc(height_cartago * sizeof(COLOR));
    }

    i = 0;
    j = 0;
    while(i < width_cartago){
        while(j < height_cartago){
            a = fgetc(fptr_cartago);   //alfa
            r = fgetc(fptr_cartago);   // red
            g = fgetc(fptr_cartago);   // green
            b = fgetc(fptr_cartago);   // blue
            t.r = r/255.0;
            t.g = g/255.0;
            t.b = b/255.0;
            texture_cartago[i][j] = t;
            j++;
        }
        j = 0;
        i++;
    }
    fclose(fptr_cartago);

    // LIMON
    if ((fptr_limon = fopen("textures/limon.avs","rb")) == NULL) {
      fprintf(stderr,"Failed to open LIMON input file\n");
      exit(-1);
    }
    
    /* Get width */
    fread(&width_limon,sizeof(int),1,fptr_limon);
    width_limon = FIX(width_limon);
    /* Get height */
    fread(&height_limon,sizeof(int),1,fptr_limon);
    height_limon = FIX(height_limon);

    texture_limon = (COLOR **)malloc(width_limon * sizeof(COLOR*));
    for (i = 0; i < width_limon; i++) {
        texture_limon[i] = (COLOR *)malloc(height_limon * sizeof(COLOR));
    }

    i = 0;
    j = 0;
    while(i < width_limon){
        while(j < height_limon){
            a = fgetc(fptr_limon);   //alfa
            r = fgetc(fptr_limon);   // red
            g = fgetc(fptr_limon);   // green
            b = fgetc(fptr_limon);   // blue
            t.r = r/255.0;
            t.g = g/255.0;
            t.b = b/255.0;
            texture_limon[i][j] = t;
            j++;
        }
        j = 0;
        i++;
    }
    fclose(fptr_limon);

    // GUANACASTE
    if ((fptr_guanacaste = fopen("textures/guanacaste.avs","rb")) == NULL) {
      fprintf(stderr,"Failed to open GUANACASTE input file\n");
      exit(-1);
    }
    
    /* Get width */
    fread(&width_guanacaste,sizeof(int),1,fptr_guanacaste);
    width_guanacaste = FIX(width_guanacaste);
    /* Get height */
    fread(&height_guanacaste,sizeof(int),1,fptr_guanacaste);
    height_guanacaste = FIX(height_guanacaste);

    texture_guanacaste = (COLOR **)malloc(width_guanacaste * sizeof(COLOR*));
    for (i = 0; i < width_guanacaste; i++) {
        texture_guanacaste[i] = (COLOR *)malloc(height_guanacaste * sizeof(COLOR));
    }

    i = 0;
    j = 0;
    while(i < width_guanacaste){
        while(j < height_guanacaste){
            a = fgetc(fptr_guanacaste);   //alfa
            r = fgetc(fptr_guanacaste);   // red
            g = fgetc(fptr_guanacaste);   // green
            b = fgetc(fptr_guanacaste);   // blue
            t.r = r/255.0;
            t.g = g/255.0;
            t.b = b/255.0;
            texture_guanacaste[i][j] = t;
            j++;
        }
        j = 0;
        i++;
    }
    fclose(fptr_guanacaste);
    
    // PUNTARENAS
    if ((fptr_puntarenas = fopen("textures/puntarenas.avs","rb")) == NULL) {
      fprintf(stderr,"Failed to open PUNTARENAS input file\n");
      exit(-1);
    }
    
    /* Get width */
    fread(&width_puntarenas,sizeof(int),1,fptr_puntarenas);
    width_puntarenas = FIX(width_puntarenas);
    /* Get height */
    fread(&height_puntarenas,sizeof(int),1,fptr_puntarenas);
    height_puntarenas = FIX(height_puntarenas);

    texture_puntarenas = (COLOR **)malloc(width_puntarenas * sizeof(COLOR*));
    for (i = 0; i < width_puntarenas; i++) {
        texture_puntarenas[i] = (COLOR *)malloc(height_puntarenas * sizeof(COLOR));
    }

    i = 0;
    j = 0;
    while(i < width_puntarenas){
        while(j < height_puntarenas){
            a = fgetc(fptr_puntarenas);   //alfa
            r = fgetc(fptr_puntarenas);   // red
            g = fgetc(fptr_puntarenas);   // green
            b = fgetc(fptr_puntarenas);   // blue
            t.r = r/255.0;
            t.g = g/255.0;
            t.b = b/255.0;
            texture_puntarenas[i][j] = t;
            j++;
        }
        j = 0;
        i++;
    }
    fclose(fptr_puntarenas);
}

COLOR texel_mapping(int x, int y, int provincia){
    COLOR texel_color;
    switch(provincia){
        case SAN_JOSE:
            x = x % width_san_jose;
            y = y % height_san_jose;
            texel_color = texture_san_jose[x][y];
            break;
        case CARTAGO:
            x = x % width_cartago;
            y = y % height_cartago;
            texel_color = texture_cartago[x][y];
            break;
        case ALAJUELA:
            x = x % width_alajuela;
            y = y % height_alajuela;
            texel_color = texture_alajuela[x][y];
            break;
        case PUNTARENAS:
            x = x % width_puntarenas;
            y = y % height_puntarenas;
            texel_color = texture_puntarenas[x][y];
            break;
        case LIMON:
            x = x % width_limon;
            y = y % height_limon;
            texel_color = texture_limon[x][y];
            break;
        case HEREDIA:
            x = x % width_heredia;
            y = y % height_heredia;
            texel_color = texture_heredia[x][y];
            break;
        case GUANACASTE:
            x = x % width_guanacaste;
            y = y % height_guanacaste;
            texel_color = texture_guanacaste[x][y];
            break;
        default:
            texel_color.r = 0.0;
            texel_color.g = 0.0;
            texel_color.b = 0.0;
            break;
    }
    //printf("RGB: %lf %lf %lf\n", texel_color.r, texel_color.g, texel_color.b);
    return texel_color;
}

// int main(int argc, char **argv) {

//     openTextureFiles();
//     texel_mapping(0, 0, ALAJUELA);
//     texel_mapping(0, 1, SAN_JOSE);
//     texel_mapping(0, 2, PUNTARENAS);
//     texel_mapping(1, 3, LIMON);
//     texel_mapping(3032, 73280, HEREDIA);
//     texel_mapping(3032, 73280, GUANACASTE);
//     texel_mapping(3032, 73280, CARTAGO);

// }