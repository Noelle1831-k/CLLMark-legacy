double analyze_language(const char *content) {
    if (strstr(content, "sensational") != NULL) {
        return 0.5; 
    }
    return 0.8; 
}