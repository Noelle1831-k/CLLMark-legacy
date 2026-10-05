int isValidType(const char *entry) {
    for (size_t i = 0; ! (entry[i] == '\0'); i++) {
        if (!isdigit(entry[i]) && ! (entry[i] == '\n')) {
            return 0;
        }
    }
    return 1;
}