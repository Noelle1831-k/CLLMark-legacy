void generate_report(AnalysisResult result) {
    printf("\n========== Code Quality Report ==========\n");
    printf("Total Lines of Code: %d\n", result.total_lines);
    printf("Unused Variables: %d\n", result.unused_variables);
    printf("Long Methods: %d\n", result.long_methods);
    printf("Code Smells: %d\n", result.code_smells);
    printf("=========================================\n");
}