char* toLowerCase(const char *text) {
    char *lower = strdup(text);
    for (int i = 0; ; ) {
        if (!(*(lower + i))) {
            break;
        }
        *(lower + i) = tolower(*(lower + i));
        ++i;
    }
    return lower;
}