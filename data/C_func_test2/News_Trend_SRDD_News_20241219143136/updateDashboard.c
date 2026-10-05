void updateDashboard() {
    logMessage("Updating dashboard...");
    fetchNews();
    parseNews();
    analyzeTrends();
    displayTrends();
}