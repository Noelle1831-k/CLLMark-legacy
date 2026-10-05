Suggestions* generate_suggestions(AnalysisResult *result) {
    if (!result) {
        fprintf(stderr, "Error: Analysis result is NULL\n");
        return NULL;
    }
    Suggestions *suggestions = (Suggestions *)malloc(sizeof(Suggestions));
    if (!suggestions) {
        fprintf(stderr, "Error: Memory allocation failed for suggestions\n");
        return NULL;
    }
    suggestions->count = result->optimization_issues + result->readability_issues + result->maintainability_issues;
    suggestions->messages = (char **)malloc(suggestions->count * sizeof(char *));
    if (!suggestions->messages) {
        fprintf(stderr, "Error: Memory allocation failed for suggestion messages\n");
        free(suggestions);
        return NULL;
    }
    for (int i = 0; i < suggestions->count; i++) {
        suggestions->messages[i] = (char *)malloc(50 * sizeof(char));
        if (!suggestions->messages[i]) {
            fprintf(stderr, "Error: Memory allocation failed for individual suggestion message\n");
            for (int j = 0; j < i; j++) {
                free(suggestions->messages[j]);
            }
            free(suggestions->messages);
            free(suggestions);
            return NULL;
        }
        sprintf(suggestions->messages[i], "Suggestion %d: Improve this part of the code.", i + 1);
    }
    return suggestions;
}