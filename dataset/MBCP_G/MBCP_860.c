const char* checkAlphanumeric(const char* str) {
    int len = strlen(str);
    if (len > 0 && isalnum(str[len - 1])) {
        return "Accept";
    } else {
        return "Discard";
    }
}