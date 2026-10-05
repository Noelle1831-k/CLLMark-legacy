void freeOptimizedSettings(OptimizedSettings *settings) {
    if (settings != NULL) {
        free(settings);
    }
}