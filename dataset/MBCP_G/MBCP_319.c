void findLongWord(const char *text, char result[][6], int *count) {
    regex_t regex;
    regmatch_t pmatch[1];
    *count = 0;
    regcomp(&regex, "\\b[A-Za-z]{5}\\b", REG_EXTENDED);
    const char *p = text;
    while (!regexec(&regex, p, 1, pmatch, 0)) {
        int start = pmatch[0].rm_so;
        int end = pmatch[0].rm_eo;
        snprintf(result[*count], end - start + 1, "%.*s", end - start, p + start);
        (*count)++;
        p += end;
    }
    regfree(&regex);
}