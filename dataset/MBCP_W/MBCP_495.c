void removeLowercase(char *str, char *result) {
    regex_t regex;
    regmatch_t match;
    int ret;
    char *buffer = (char *)malloc(sizeof(char) * 100);
    buffer[0] = '\0';
    ret = regcomp(&regex, "[a-z]+", REG_EXTENDED);
    if (ret) {
        return;
    }
    strcpy(result, str);
    while (regexec(&regex, result, 1, &match, 0) == 0) {
        int len = match.rm_eo - match.rm_so;
        strncpy(buffer, result, match.rm_so);
        buffer[match.rm_so] = '\0';
        strcat(buffer, result + match.rm_eo);
        strcpy(result, buffer);
    }
    regfree(&regex);
}