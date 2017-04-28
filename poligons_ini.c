//poligons initialization

//initialize the first get_poligon : STAR
Real_PointNodePtr first_poligon () {    
    Real_PointNodePtr col3 = r_create_list();

    Real_Point A;
    A.x = 50.1; A.y = 100.4;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 125.2; A.y = 300.4;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 25.0; A.y = 400.3;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 175.6; A.y = 399.7;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 300.9; A.y = 500.8;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 425.8; A.y = 403;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 665.7; A.y = 405;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 465.6; A.y = 300.1;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 550.4; A.y = 100.0;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 300.3; A.y = 200.2;
    col3 = r_insert_node_last_pro(A, col3);

    return col3;
}

//initialize the first get_poligon :TRIANGLE
Real_PointNodePtr second_poligon () {    
    Real_PointNodePtr col3 = r_create_list();

    Real_Point A;
    A.x = 50.1; A.y = 500.4;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 150.2; A.y = 799.4;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 250.0; A.y = 500.4;
    col3 = r_insert_node_last_pro(A, col3);

    return col3;
}

//initialize the first get_poligon : SQUARE
Real_PointNodePtr third_poligon () {    
    Real_PointNodePtr col3 = r_create_list();

    Real_Point A;
    A.x = 560.1; A.y = 100.4;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 560.1; A.y = 300.4;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 710.1; A.y = 300.3;
    col3 = r_insert_node_last_pro(A, col3);
    A.x = 710.2; A.y = 100.4;
    col3 = r_insert_node_last_pro(A, col3);
  
    return col3;
}