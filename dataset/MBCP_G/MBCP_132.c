void tupString(char *result, char *tup[], size_t size) {
    strcpy(result, "");
    for (size_t i = 0; i < size; i++) {
        strcat(result, tup[i]);
    }
}