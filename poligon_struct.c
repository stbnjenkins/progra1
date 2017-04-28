
typedef struct Poligon_Node{
    Real_PointNodePtr list_of_point;
    double R, G, B;
    int mode;
    struct Poligon_Node *next;
} Poligon_Node, *Poligon_NodePtr;

//Creating Node
Poligon_NodePtr poligon_create_list(){
    Poligon_NodePtr first;
    first = NULL;
    return first;
}

//Creating Node
Poligon_NodePtr poligon_create_node(Real_PointNodePtr myPointList, double R, double G, double B, int mode){
    Poligon_NodePtr newnode = (Poligon_NodePtr) malloc(sizeof(Poligon_Node));
    if (newnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    } else {
        newnode->list_of_point = myPointList;
        newnode->R = R;
        newnode->G = G;
        newnode->B = B;
        newnode->mode = mode;
        newnode->next = NULL;
        return newnode;
    }
}

//Inserting Node at Last
Poligon_NodePtr poligon_insert_node_last(Real_PointNodePtr myPointList, double R, double G, double B, int mode, Poligon_NodePtr first){
    Poligon_NodePtr ptr,newnode;  
    newnode = poligon_create_node(myPointList, R, G, B, mode);
    if (first == NULL) {
        first = newnode;
        first->next = NULL;
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next == NULL){
                ptr->next = newnode;
                newnode->next = NULL;
                return first;
            }
        }
    }
}   