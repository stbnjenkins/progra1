//frame manager
#include "san_jose.c"
#include "alajuela.c"
#include "cartago.c"
//#include "heredia.c"
#include "puntarenas.c"
#include "limon.c"
#include "guanacaste.c"

Poligon_NodePtr list_of_provinces = NULL;

//create list of provinces poligons
Poligon_NodePtr create_list_of_provinces (){
    Poligon_NodePtr first = poligon_create_list();
    Real_PointNodePtr list_of_points;

    //including San Jose
    list_of_points = chepe_poligon();
    first = poligon_insert_node_last(list_of_points, 0.6, 0.4, 1, 0, first);

    //including Cartago
    list_of_points = cartago_poligon();
    first = poligon_insert_node_last(list_of_points, 0, 0, 1, 1, first);

    //including Alajuela
    list_of_points = alajuela_poligon();
    first = poligon_insert_node_last(list_of_points, 1, 0, 0, 2, first);

    // //including Puntarenas 1
    list_of_points = puntarenas_poligon();
    first = poligon_insert_node_last(list_of_points, 1, 0.4, 0, 3, first);

    // // //including Puntarenas 2
    // // list_of_points = first_poligon();
    // // first = poligon_insert_node_last(list_of_points, 1, 0.4, 0, 3, first);

    // //including Limon
    list_of_points = limon_poligon();
    first = poligon_insert_node_last(list_of_points, 0, 1, 0, 4, first);

    // // //including Heredia
    // // list_of_points = first_poligon();
    // // first = poligon_insert_node_last(list_of_points, 1, 1, 0, 5, first);

    // //including Guana
    list_of_points = guanacaste_poligon();
    first = poligon_insert_node_last(list_of_points, 0.43, 0.27, 0.002, 6, first);

    return first;
}

//Plot Poligon list border only
void plot_poligon_list_border_only (Poligon_NodePtr first, int res){
    ini_buffer(res);
    point_list_delete();
    r_point_list_delete();
    line_list_delete();
    Poligon_NodePtr ptr;
    Real_PointNodePtr real_temp, clipped;
    PointNodePtr int_temp;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No Poligons in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            real_temp = ptr->list_of_point;
            clipped = clipping (real_temp, 1, 1,  549, 549);
            int_temp = map_real_to_int_point_list(clipped);
            create_poligon_to_buffer (int_temp);
        }
    }
    plot_framebuffer(res);
}

//Plot Poligon list fill
void plot_poligon_list_fill (Poligon_NodePtr first, int res){
    ini_buffer(res);
    point_list_delete();
    r_point_list_delete();
    line_list_delete();
    Poligon_NodePtr ptr;
    Real_PointNodePtr real_temp, clipped;
    PointNodePtr int_temp;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No Poligons in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            real_temp = ptr->list_of_point;
            clipped = clipping (real_temp, 1, 1,  549, 549);
            int_temp = map_real_to_int_point_list(clipped);
            fill_poligon_to_buffer (int_temp, 1, 549, ptr->R, ptr->G, ptr->B, 7);
        }
    }
    plot_framebuffer(res);
}

//Plot Poligon list fill with texel
void plot_poligon_list_fil_with_texel (Poligon_NodePtr first, int res){
    ini_buffer(res);
    point_list_delete();
    r_point_list_delete();
    line_list_delete();
    Poligon_NodePtr ptr;
    Real_PointNodePtr real_temp, clipped;
    PointNodePtr int_temp;
    if (first == NULL) {
        printf("\nEMPTY LIST:");
        printf(":No Poligons in the list to display\n");
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            real_temp = ptr->list_of_point;
            clipped = clipping (real_temp, 1, 1,  549, 549);
            int_temp = map_real_to_int_point_list(clipped);
            fill_poligon_to_buffer (int_temp, 1, 549, ptr->R, ptr->G, ptr->B, ptr->mode);
        }
    }
    plot_framebuffer(res);
}

//Run plotter with mode
void frame_plotter (int res, int disp_mode){
    if (disp_mode == 0) {
        plot_poligon_list_border_only (list_of_provinces, res);
    } else if (disp_mode == 1) {
        plot_poligon_list_fill (list_of_provinces, res);
    } else if (disp_mode == 2) {
        plot_poligon_list_fil_with_texel (list_of_provinces, res);
    }
} 