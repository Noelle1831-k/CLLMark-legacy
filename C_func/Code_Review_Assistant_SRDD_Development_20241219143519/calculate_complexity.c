int calculate_complexity(const char *code) {
    if (!code) {
        fprintf(stderr, "Error: Provided code is NULL\n");
        return -1;
    }
    int complexity = 0;
    for (const char *c = code; *c != '\0'; c++) {
        if (*c == '{' || *c == '}') {
            complexity++;
        }
    }
    return complexity;
}