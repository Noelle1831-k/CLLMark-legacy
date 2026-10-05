int isAllowedSpecificChar(const char *str) {
    regex_t regex;
    int ret;
    ret = regcomp(&regex, "^[a-zA-Z0-9]+$", REG_EXTENDED);
    if (ret) {
        return 0; 
    }
    ret = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex);
    return !ret;
}