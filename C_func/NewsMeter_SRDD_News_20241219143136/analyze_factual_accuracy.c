double analyze_factual_accuracy(const char *content) {
    if (strstr(content, "factually incorrect") != NULL) {
        return 0.4; 
    }
    return 0.9; 
}