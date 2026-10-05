char* suggest_refactoring(const char *code) {
    char *suggestions = (char *)malloc(256 * sizeof(char));
    if (suggestions == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(suggestions, "Consider the following refactoring techniques:\n");
    if (strstr(code, "if") != NULL) strcat(suggestions, "- Simplify conditional expressions.\n");
    if (strstr(code, "for") != NULL) strcat(suggestions, "- Use enhanced for loops where applicable.\n");
    if (strstr(code, "while") != NULL) strcat(suggestions, "- Convert while loops to for loops if possible.\n");
    if (strstr(code, "switch") != NULL) strcat(suggestions, "- Refactor switch statements to polymorphism.\n");
    return suggestions;
}