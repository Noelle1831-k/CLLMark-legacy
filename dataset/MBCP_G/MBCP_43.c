char* textMatch(const char* text) {
    regex_t regex;
    int reti;
    static char result[15];
    reti = regcomp(&regex, "^[a-z]+_[a-z]+$", REG_EXTENDED);
    if (reti) {
        strcpy(result, "Not matched!");
        return result;
    }
    reti = regexec(&regex, text, 0, NULL, 0);
    if (!reti) {
        strcpy(result, "Found a match!");
    } else {
        strcpy(result, "Not matched!");
    }
    regfree(&regex);
    return result;
}