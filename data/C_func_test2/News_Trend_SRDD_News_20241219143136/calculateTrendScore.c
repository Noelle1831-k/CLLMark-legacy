int calculateTrendScore(const char *topic) {
    logMessage("Calculating trend score...");
    int score = strlen(topic) * 10; 
    return score;
}