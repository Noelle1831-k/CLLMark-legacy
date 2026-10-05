void getStringInput(char *dest, size_t size) {
    fgets(dest, size, stdin);
    size_t len = strlen(dest);
    if (len > 0 && dest[len - 1] == '\n') {
        dest[len - 1] = '\0';
    }
}