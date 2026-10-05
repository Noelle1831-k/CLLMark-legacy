void customize_graph(Graph *graph) {
    printf("Customizing graph...\n");
    printf("Enter a custom title for the graph: ");
    fgets(graph->title, sizeof(graph->title), stdin);
    graph->title[strcspn(graph->title, "\n")] = '\0';  
}