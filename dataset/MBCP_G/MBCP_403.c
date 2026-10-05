bool isValidUrl(const char *str) {
    const char *pattern = "^(https?|ftp):
    regex_t regex;
    int ret;
    ret = regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);
    if (ret) {
        return false;
    }
    ret = regexec(&regex, str, 0, NULL, 0);
    regfree(&regex);
    if (!ret) {
        return true;
    } else {
        return false;
    }
}