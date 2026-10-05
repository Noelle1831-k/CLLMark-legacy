void TimeTracker::generateReport() const {
    reportGenerator.generateCategorySummary(activities);
    reportGenerator.generateDetailedReport(activities);
}