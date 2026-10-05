char* textMatch(const char* text) {
    regex_t regex;
    int reti;
    const char* pattern = "^ab*$";
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) return "Regex compilation failed!";
    reti = regexec(&regex, text, 0, NULL, 0);
    regfree(&regex);
    if (!reti) return "Found a match!";
    else return "Not matched!";
}