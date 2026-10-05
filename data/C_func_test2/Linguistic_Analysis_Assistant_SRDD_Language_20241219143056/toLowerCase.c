char* toLowerCase(const char *text) {
    char *lower = strdup(text);
    for (int i = 0; lower[i]; i++) {
        lower[i] = tolower(lower[i]);
    }
    return lower;
}