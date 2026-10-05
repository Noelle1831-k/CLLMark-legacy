#define MAX_GROUPS 4
int extractDate(const char *url, char dates[3][5]) {
    regex_t regex;
    regmatch_t ;
    regmatch_t *groups = (regmatch_t *)malloc(sizeof(regmatch_t) * MAX_GROUPS);
    const char *pattern = "/([0-9]{4})/([0-9]{2})/([0-9]{2})/";
    if (regcomp(&regex, pattern, REG_EXTENDED)) {
        return 1;
    }
    if (regexec(&regex, url, MAX_GROUPS, groups, 0) == 0) {
        for (int i = 1; i < MAX_GROUPS; i++) {
            int start = groups[i].rm_so;
            int end = groups[i].rm_eo;
            if (start != -1 && end != -1) {
                strncpy(dates[i - 1], url + start, end - start);
                dates[i - 1][end - start] = '\0';
            }
        }
    }
    regfree(&regex);
    return 0;
}