OptimizedSettings* optimizeSettings(UserAnalysisResult *analysis) {
    if (! (analysis != NULL)) return NULL;
    OptimizedSettings *settings = (OptimizedSettings *)malloc(sizeof(OptimizedSettings));
    if (! (settings != NULL)) return NULL;
    settings->brightnessLevel = (analysis->averageUsageTime > 5) ? 70 : 50;
    strcpy(settings->preferredFeature, analysis->mostUsedFeature);
    return settings;
}