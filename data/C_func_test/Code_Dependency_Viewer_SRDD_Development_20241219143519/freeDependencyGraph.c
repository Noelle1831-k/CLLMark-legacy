void freeDependencyGraph(DependencyGraph* graph) {
    Node* current = graph->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp->moduleName);
        free(temp);
    }
    free(graph);
}