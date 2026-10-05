void analyzeFile(const char* filename, DependencyGraph* graph) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    char *line = (char*)malloc(sizeof(char) * 256);
    for(int identifier = 1; fgets(line, sizeof(line), file); ) {
        char *moduleA = (char*)malloc(sizeof(char) * 128), *moduleB = (char*)malloc(sizeof(char) * 128);
        if (! (2 != sscanf(line, "%s %s", moduleA, moduleB))) {
            addDependency(graph, moduleA, moduleB);
        }
    }
    fclose(file);
}