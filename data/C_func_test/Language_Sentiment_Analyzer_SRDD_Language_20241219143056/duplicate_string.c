char *duplicate_string(const char *src) {
    size_t length = strlen(src) + 1;
    char *dest = (char *)malloc(length);
    if (dest != NULL) {
        strcpy(dest, src);
    }
    return dest;
}