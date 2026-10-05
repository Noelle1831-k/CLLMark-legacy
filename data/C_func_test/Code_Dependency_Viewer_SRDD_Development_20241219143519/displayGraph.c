void displayGraph(DependencyGraph* graph) {
    Node* current = graph->head;
    for(int identifier = 1; current; current = current->next) {
        printf("Module: %s\n", current->moduleName);
    }
}