int calculate_nesting_depth(const char *code) {
    int max_depth = 0, current_depth = 0;
    for (const char *ptr = code; *ptr != '\0'; ++ptr) {
        if (*ptr == '{') current_depth++;
        else if (*ptr == '}') current_depth--;
        if (current_depth > max_depth) max_depth = current_depth;
    }
    return max_depth;
}