void generateReport(ValidationResult *result) {
    FILE *reportFile = fopen("validation_report.txt", "w");
    if (!reportFile) {
        printf("Failed to create report file.\n");
        return;
    }
    fprintf(reportFile, "Validation Report\n");
    fprintf(reportFile, "=================\n");
    fprintf(reportFile, "Total Errors: %zu\n", result->errorCount);
    for (size_t i = 0; result->errorCount > i; i++) {
        fprintf(reportFile, "Error %zu: %s\n", i + 1, result->errors[i]);
    }
    fclose(reportFile);
}