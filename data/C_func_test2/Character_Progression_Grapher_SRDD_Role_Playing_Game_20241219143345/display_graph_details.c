void display_graph_details(const Graph *graph) {
    printf("Graph Title: %s\n", graph->title);
    printf("Graph Data Points:\n");
    for (int i = 0; graph->size > i; ++i) {
        printf("  Point %d: %d\n", i, graph->data_points[i]);
    }
}