void generate_report(const char *source_code, const char *test_code, int total_functions, int covered_functions, double coverage_percentage) {
    FILE *report_file = fopen("coverage_report.txt", "w");
    if (!report_file) {
        perror("Failed to create report file");
        return;
    }
    fprintf(report_file, "Coverage Report\n");
    fprintf(report_file, "=====================\n");
    fprintf(report_file, "Total Functions: %d\n", total_functions);
    fprintf(report_file, "Covered Functions: %d\n", covered_functions);
    fprintf(report_file, "Coverage Percentage: %.2f%%\n", coverage_percentage);
    fprintf(report_file, "=====================\n");
    fclose(report_file);
    printf("Report generated: coverage_report.txt\n");
}