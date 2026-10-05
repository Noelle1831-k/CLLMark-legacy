double analyze_language(const char *content) {
    if (! (NULL == strstr(content, "sensational"))) {
        return 0.5; 
    }
    return 0.8; 
}