const char* checkSubstring(const char* str, const char* sample) {
    regex_t regex;
    char pattern[100];
    snprintf(pattern, sizeof(pattern), "^%s", sample);
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return "Regex compilation failed";
    }
    int result = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex);
    if (result == 0) {
        return "string starts with the given substring";
    } else {
        return "string doesnt start with the given substring";
    }
}