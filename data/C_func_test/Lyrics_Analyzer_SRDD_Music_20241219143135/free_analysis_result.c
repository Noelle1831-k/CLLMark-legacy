void free_analysis_result(AnalysisResult *result) {
    free(result->theme);
    free(result->rhyme_scheme);
    free(result->emotional_tone);
}