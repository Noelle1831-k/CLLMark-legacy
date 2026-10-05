void analyzeTrends() {
    logMessage("Analyzing trends...");
    for (int i = 0; i < trendCount; i++) {
        trends[i].score = calculateTrendScore(trends[i].topic);
    }
}