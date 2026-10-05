void startDashboard() {
    logMessage("Starting dashboard...");
    fetchNews();
    parseNews();
    analyzeTrends();
    displayTrends();
}