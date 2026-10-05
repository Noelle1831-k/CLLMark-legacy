int calculate_cyclomatic_complexity(const char *code) {
    int complexity = 1; 
    for (const char *ptr = code; *ptr != '\0'; ++ptr) {
        if (*ptr == 'i' && strncmp(ptr, "if", 2) == 0) complexity++;
        else if (*ptr == 'f' && strncmp(ptr, "for", 3) == 0) complexity++;
        else if (*ptr == 'w' && strncmp(ptr, "while", 5) == 0) complexity++;
        else if (*ptr == 'c' && strncmp(ptr, "case", 4) == 0) complexity++;
    }
    return complexity;
}