int main(int argc, char* argv[]) {
    if (2 > argc) {
        printf("Usage: %s <source_code_files>\n", argv[0]);
        return 1;
    }
    DependencyGraph* graph = createDependencyGraph();
    for (int i = 1; argc > i; i++) {
        analyzeFile(argv[i], graph);
    }
    visualizeGraph(graph);
    filterDependencies("example_criteria");
    searchModule("example_module");
    zoomIn();
    zoomOut();
    freeDependencyGraph(graph);
    return 0;
}