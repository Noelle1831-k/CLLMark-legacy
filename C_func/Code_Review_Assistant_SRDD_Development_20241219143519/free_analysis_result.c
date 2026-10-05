void free_analysis_result(AnalysisResult *result) {
    if (result) {
        free(result);
    }
}