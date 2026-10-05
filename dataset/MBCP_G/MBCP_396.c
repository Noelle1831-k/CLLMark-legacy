const char* checkChar(const char* str) {
    regex_t regex;
    const char* pattern = "^(.).*\1$";
    int reti;
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        regfree(&regex);
        return "Invalid";
    }
    reti = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex);
    if (!reti) {
        return "Valid";
    } else {
        return "Invalid";
    }
}