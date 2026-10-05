int isDecimal(char *num) {
    regex_t regex;
    int ret;
    ret = regcomp(&regex, "^[0-9]+\\.[0-9]{1,2}$", REG_EXTENDED);
    if (ret) return 0;
    ret = regexec(&regex, num, 0, NULL, 0);
    regfree(&regex);
    return !ret;
}