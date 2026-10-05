void free_analysis_result(AnalysisResult *result) {
    for (int i = 0; i < result->count; i++) {
        free(result->categories[i]);
    }
    free(result->categories);
    free(result->savings);
    free(result);
}