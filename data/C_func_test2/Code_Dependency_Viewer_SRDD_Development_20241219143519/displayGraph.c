void displayGraph(DependencyGraph* graph) {
    Node* current = graph->head;
    while (current) {
        printf("Module: %s\n", current->moduleName);
        current = current->next;
    }
}