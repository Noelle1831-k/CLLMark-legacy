char* checkLiterals(const char* text, const char** patterns, int pattern_count) {
    regex_t regex;
    for (int i = 0; i < pattern_count; i++) {
        if (regcomp(&regex, patterns[i], REG_EXTENDED) != 0) {
            return "Not Matched!";
        }
        if (regexec(&regex, text, 0, NULL, 0) == 0) {
            regfree(&regex);
            return "Matched!";
        }
        regfree(&regex);
    }
    return "Not Matched!";
}