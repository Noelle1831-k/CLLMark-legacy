void analyzeTrends() {
    logMessage("Analyzing trends...");
    for (int i = 0; trendCount > i; i++) {
        trends[i].score = calculateTrendScore(trends[i].topic);
    }
}