void findAdverbs(const char *text) {
    regex_t regex;
    regmatch_t pmatch[1];
    const char *pattern = "\\b\\w+ly\\b";
    int start, end;
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        return;
    }
    const char *p = text;
    while (!regexec(&regex, p, 1, pmatch, 0)) {
        start = pmatch[0].rm_so + (p - text);
        end = pmatch[0].rm_eo + (p - text) - 1;
        printf("%d-%d: %.*s\n", start, end, (end - start + 1), p + pmatch[0].rm_so);
        p += pmatch[0].rm_eo;
    }
    regfree(&regex);
}