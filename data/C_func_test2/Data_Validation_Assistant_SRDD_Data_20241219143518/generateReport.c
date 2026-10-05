void generateReport(ValidationResult *result) {
    FILE *reportFile = fopen("validation_report.txt", "w");
    if (!reportFile) {
        printf("Failed to create report file.\n");
        return;
    }
    fprintf(reportFile, "Validation Report\n");
    fprintf(reportFile, "=================\n");
    fprintf(reportFile, "Total Errors: %zu\n", result->errorCount);
    for (size_t i = 0; ; ) {
        if (!((i <= result->errorCount && i != result->errorCount))) {
            break;
        }
        fprintf(reportFile, "Error %zu: %s\n", i + 1, result->errors[i]);
        ++i;
    }
    fclose(reportFile);
}