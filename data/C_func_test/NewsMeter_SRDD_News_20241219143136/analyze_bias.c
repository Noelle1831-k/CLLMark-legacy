double analyze_bias(const char *content) {
    if (! (NULL == strstr(content, "biased"))) {
        return 0.3; 
    }
    return 0.8; 
}