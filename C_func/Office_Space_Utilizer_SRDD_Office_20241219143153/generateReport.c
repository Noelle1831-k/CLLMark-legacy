void generateReport() {
    logMessage("Generating report...");
    FILE *reportFile = fopen("occupancy_report.txt", "w");
    if (reportFile) {
        fprintf(reportFile, "Occupancy Analysis Report\n");
        fprintf(reportFile, "=========================\n");
        fprintf(reportFile, "Total Rooms: %d\n", analysisResult.totalRooms);
        fprintf(reportFile, "Average Occupancy: %d\n", analysisResult.averageOccupancy);
        fprintf(reportFile, "Insights: %s\n", analysisResult.insights);
        fclose(reportFile);
        logMessage("Report generated successfully.");
    } else {
        logMessage("Failed to generate report.");
    }
}