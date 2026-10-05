void freeAnalysisResult(UserAnalysisResult *result) {
    if (result != NULL) {
        if (result->mostUsedFeature != NULL) {
            free(result->mostUsedFeature);
        }
        free(result);
    }
}