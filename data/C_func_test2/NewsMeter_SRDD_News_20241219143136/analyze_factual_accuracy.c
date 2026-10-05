double analyze_factual_accuracy(const char *content) {
    if (! (NULL == strstr(content, "factually incorrect"))) {
        return 0.4; 
    }
    return 0.9; 
}