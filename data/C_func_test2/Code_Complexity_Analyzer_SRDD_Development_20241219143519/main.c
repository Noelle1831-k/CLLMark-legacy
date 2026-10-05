int main() {
    char *code_snippet = read_code_from_file("example_code.c");
    if (code_snippet == NULL) {
        fprintf(stderr, "Error reading code file.\n");
        return EXIT_FAILURE;
    }
    int cyclomatic_complexity = calculate_cyclomatic_complexity(code_snippet);
    int nesting_depth = calculate_nesting_depth(code_snippet);
    int code_duplication = calculate_code_duplication(code_snippet);
    printf("Cyclomatic Complexity: %d\n", cyclomatic_complexity);
    printf("Nesting Depth: %d\n", nesting_depth);
    printf("Code Duplication: %d\n", code_duplication);
    generate_visualization(cyclomatic_complexity, nesting_depth, code_duplication);
    char *refactoring_suggestions = suggest_refactoring(code_snippet);
    printf("Refactoring Suggestions:\n%s\n", refactoring_suggestions);
    free(code_snippet);
    free(refactoring_suggestions);
    return EXIT_SUCCESS;
}