void init_graph(Graph *graph) {
    graph->size = 0;
    memset(graph->data_points, 0, sizeof(graph->data_points));
    strncpy(graph->title, "Character Progression Graph", sizeof(graph->title) - 1);
    graph->title[sizeof(graph->title) - 1] = '\0';
}