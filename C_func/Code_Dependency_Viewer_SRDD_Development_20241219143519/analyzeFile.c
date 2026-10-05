void analyzeFile(const char* filename, DependencyGraph* graph) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char moduleA[128], moduleB[128];
        if (sscanf(line, "%s %s", moduleA, moduleB) == 2) {
            addDependency(graph, moduleA, moduleB);
        }
    }
    fclose(file);
}