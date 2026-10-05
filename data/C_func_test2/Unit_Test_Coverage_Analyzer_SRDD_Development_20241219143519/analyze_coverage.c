int analyze_coverage(const char *source_path, const char *test_path) {
    char *source_code = read_file(source_path);
    char *test_code = read_file(test_path);
    if (!source_code || !test_code) {
        return 0;
    }
    int total_functions = count_functions(source_code);
    int covered_functions = count_covered_functions(source_code, test_code);
    double coverage_percentage = ((double)covered_functions / total_functions) * 100.0;
    printf("Total Functions: %d\n", total_functions);
    printf("Covered Functions: %d\n", covered_functions);
    printf("Coverage Percentage: %.2f%%\n", coverage_percentage);
    generate_report(source_code, test_code, total_functions, covered_functions, coverage_percentage);
    free(source_code);
    free(test_code);
    return 1;
}