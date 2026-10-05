AnalysisResult analyze_code(const char *source_code) {
    AnalysisResult result;
    result.total_lines = count_lines(source_code);
    result.unused_variables = detect_unused_variables(source_code);
    result.long_methods = detect_long_methods(source_code);
    result.code_smells = detect_code_smells(source_code);
    return result;
}