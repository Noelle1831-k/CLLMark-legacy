AnalysisResult* analyzeCode(const char *sourceCode) {
    AnalysisResult *result = (AnalysisResult *)malloc(sizeof(AnalysisResult));
    if (!result) return NULL;
    result->indentationIssues = detectIndentationIssues(sourceCode);
    result->unusedVariables = detectUnusedVariables(sourceCode);
    result->namingConventions = detectNamingConventionViolations(sourceCode);
    result->missingComments = detectMissingComments(sourceCode);
    return result;
}