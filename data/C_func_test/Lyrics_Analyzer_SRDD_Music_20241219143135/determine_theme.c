char* determine_theme(const char *lyrics) {
    char *theme = (char *)malloc(50 * sizeof(char));
    if (theme == NULL) {
        fprintf(stderr, "Memory allocation failed for theme\n");
        exit(EXIT_FAILURE);
    }
    strcpy(theme, "Love");
    return theme;
}