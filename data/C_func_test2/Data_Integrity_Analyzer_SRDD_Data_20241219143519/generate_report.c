void generate_report(const IntegrityResults *results) {
    FILE *report = fopen("report.txt", "w");
    if (!report) {
        log_message("Error: Unable to create report file.");
        return;
    }
    fprintf(report, "Data Integrity Analysis Report\n");
    fprintf(report, "==============================\n");
    fprintf(report, "Consistency: %.2f%%\n", results->consistency);
    fprintf(report, "Accuracy: %.2f%%\n", results->accuracy);
    fprintf(report, "Completeness: %.2f%%\n", results->completeness);
    fprintf(report, "Validity: %.2f%%\n", results->validity);
    fclose(report);
}