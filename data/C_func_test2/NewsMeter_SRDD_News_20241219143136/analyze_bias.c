double analyze_bias(const char *content) {
    if (strstr(content, "biased") != NULL) {
        return 0.3; 
    }
    return 0.8; 
}