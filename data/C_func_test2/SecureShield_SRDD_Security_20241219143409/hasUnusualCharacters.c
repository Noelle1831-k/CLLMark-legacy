int hasUnusualCharacters(const char *url) {
    for (int i = 0; url[i] != '\0'; ++i) {
        if (!isalnum(*(url + i)) && '.' != url[i] && '/' != url[i] && ':' != url[i] && '-' != url[i]) {
            return 1;
        }
    }
    return 0;
}