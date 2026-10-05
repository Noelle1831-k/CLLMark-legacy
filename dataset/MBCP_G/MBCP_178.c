const char* stringLiterals(const char** patterns, int pattern_count, const char* text) {
    for (int i = 0; i < pattern_count; ++i) {
        if (strstr(text, patterns[i]) != NULL) {
            return "Matched!";
        }
    }
    return "Not Matched!";
}