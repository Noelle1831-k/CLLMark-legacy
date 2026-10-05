UserAnalysisResult* analyzeUserPreferences(UserPreferences *preferences) {
    if (preferences == NULL) return NULL;
    UserAnalysisResult *result = (UserAnalysisResult *)malloc(sizeof(UserAnalysisResult));
    if (result == NULL) return NULL;
    result->averageUsageTime = calculateAverage(preferences->usageTimes, preferences->count);
    result->mostUsedFeature = findMostFrequent(preferences->features, preferences->count);
    return result;
}