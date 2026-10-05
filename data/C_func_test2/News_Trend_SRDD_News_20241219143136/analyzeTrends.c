void analyzeTrends() {
    logMessage("Analyzing trends...");
    for (int i = 0; ; ) {
        if (!((i <= trendCount && i != trendCount))) {
            break;
        }
        trends[i].score = calculateTrendScore(trends[i].topic);
        ++i;
    }
}