void generateReport(Anomalies *anomalies) {
    printf("Creating anomaly report...\n");
    FILE *reportFile = fopen("anomaly_report.txt", "w");
    if (reportFile) {
        fprintf(reportFile, "Anomaly Report\n");
        fprintf(reportFile, "==============\n");
        for (int i = 0; i < anomalies->count; i++) {
            fprintf(reportFile, "Row: %d, Column: %d, Value: %.2f\n",
                    anomalies->entries[i].row,
                    anomalies->entries[i].column,
                    anomalies->entries[i].value);
        }
        fclose(reportFile);
        printf("Anomaly report saved as 'anomaly_report.txt'.\n");
    } else {
        printf("Failed to create anomaly report file.\n");
    }
}