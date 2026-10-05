const char* match(const char* text) {
    regex_t regex;
    int reti;
    const char* pattern = "[A-Z][a-z]+";
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        regfree(&regex);
        return "No";
    }
    reti = regexec(&regex, text, 0, NULL, 0);
    regfree(&regex);
    if (!reti) {
        return "Yes";
    } else {
        return "No";
    }
}