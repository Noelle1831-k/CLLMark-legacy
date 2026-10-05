int main() {
    printf("Welcome to PersonalizationOptimizer!\n");
    char *userDataFile = "user_data.txt";
    char *settingsFile = "settings.txt";
    UserPreferences *userPreferences = loadUserPreferences(userDataFile);
    if (userPreferences == NULL) {
        printf("Error: Failed to load user data.\n");
        return 1;
    }
    UserAnalysisResult *analysisResult = analyzeUserPreferences(userPreferences);
    if (analysisResult == NULL) {
        printf("Error: Failed to analyze user data.\n");
        freeUserPreferences(userPreferences);
        return 1;
    }
    OptimizedSettings *optimizedSettings = optimizeSettings(analysisResult);
    if (optimizedSettings == NULL) {
        printf("Error: Failed to optimize settings.\n");
        freeUserPreferences(userPreferences);
        freeAnalysisResult(analysisResult);
        return 1;
    }
    if (!saveOptimizedSettings(settingsFile, optimizedSettings)) {
        printf("Error: Failed to save optimized settings.\n");
    } else {
        printf("Optimized settings saved successfully.\n");
    }
    freeUserPreferences(userPreferences);
    freeAnalysisResult(analysisResult);
    freeOptimizedSettings(optimizedSettings);
    printf("Thank you for using PersonalizationOptimizer!\n");
    return 0;
}