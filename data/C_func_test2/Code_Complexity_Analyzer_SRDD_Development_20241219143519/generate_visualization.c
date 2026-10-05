void generate_visualization(int cyclomatic_complexity, int nesting_depth, int code_duplication) {
    printf("Generating Visualization...\n");
    printf("Cyclomatic Complexity: ");
    for (int i = 0; i < cyclomatic_complexity; i++) printf("*");
    printf("\n");
    printf("Nesting Depth: ");
    for (int i = 0; i < nesting_depth; i++) printf("#");
    printf("\n");
    printf("Code Duplication: ");
    for (int i = 0; i < code_duplication; i++) printf("@");
    printf("\n");
}