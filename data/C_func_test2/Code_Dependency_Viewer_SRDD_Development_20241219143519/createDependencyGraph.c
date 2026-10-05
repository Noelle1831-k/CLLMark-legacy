DependencyGraph* createDependencyGraph() {
    DependencyGraph* graph = (DependencyGraph*)malloc(sizeof(DependencyGraph));
    graph->head = NULL;
    return graph;
}