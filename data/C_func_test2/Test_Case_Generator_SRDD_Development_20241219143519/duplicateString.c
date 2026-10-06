char* duplicateString(const char *str) {
    char *dup = (char *)malloc(strlen(str) + 1);
    if (dup) {
        strcpy(dup, str);
    }
    return dup;
}