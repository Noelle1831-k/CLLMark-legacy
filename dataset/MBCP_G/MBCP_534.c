void searchLiteral(const char *pattern, const char *text, int *start, int *end) {
    char *pos = strstr(text, pattern);
    if (pos != NULL) {
        *start = pos - text;
        *end = *start + strlen(pattern) - 1;
    } else {
        *start = -1; 
        *end = -1;   
    }
}