void addDependency(DependencyGraph* graph, const char* moduleA, const char* moduleB) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->moduleName = strdup(moduleB);
    newNode->next = graph->head;
    graph->head = newNode;
}