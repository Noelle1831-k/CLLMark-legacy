int hasUnusualCharacters(const char *url) {
    for (int i = 0; ! ('\0' == url[i]); i++) {
        if (!isalnum(url[i]) && ! (url[i] == '.') && ! (url[i] == '/') && ! (url[i] == ':') && ! (url[i] == '-')) {
            return 1;
        }
    }
    return 0;
}