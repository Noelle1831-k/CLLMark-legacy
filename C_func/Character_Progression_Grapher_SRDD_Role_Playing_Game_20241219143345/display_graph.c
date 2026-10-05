void display_graph(UserInterface *ui, Graph *graph) {
    printf("Displaying graph...\n");
    for (int i = 0; i < graph->size; ++i) {
        printf("Data point %d: %d\n", i, graph->data_points[i]);
    }
}