int checkEmail(const char *email) {
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    regex_t regex;
    int reti;
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) { return 0; }
    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    return !reti;
}