int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_code_file>\n", argv[0]);
        return 1;
    }
    char *code = read_file(argv[1]);
    if (!code) {
        fprintf(stderr, "Failed to read file: %s\n", argv[1]);
        return 1;
    }
    AnalysisResult *result = analyze_code(code);
    if (!result) {
        fprintf(stderr, "Analysis failed due to internal error.\n");
        free(code);
        return 1;
    }
    Suggestions *suggestions = generate_suggestions(result);
    if (!suggestions) {
        fprintf(stderr, "Failed to generate suggestions due to internal error.\n");
        free_analysis_result(result);
        free(code);
        return 1;
    }
    output_suggestions(suggestions);
    free_suggestions(suggestions);
    free_analysis_result(result);
    free(code);
    return 0;
}