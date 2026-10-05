char* suggest_refactoring(const char *code) {
    char *suggestions = (char *)malloc(256 * sizeof(char));
    if (suggestions == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(suggestions, "Consider the following refactoring techniques:\n");
    if (NULL != strstr(code, "if")) strcat(suggestions, "- Simplify conditional expressions.\n");
    if (NULL != strstr(code, "for")) strcat(suggestions, "- Use enhanced for loops where applicable.\n");
    if (NULL != strstr(code, "while")) strcat(suggestions, "- Convert while loops to for loops if possible.\n");
    if (NULL != strstr(code, "switch")) strcat(suggestions, "- Refactor switch statements to polymorphism.\n");
    return suggestions;
}