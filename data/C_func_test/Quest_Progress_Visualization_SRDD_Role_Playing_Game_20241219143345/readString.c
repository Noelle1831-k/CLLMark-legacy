char *readString() {
    char *str = malloc(256);
    scanf(" %[^\n]", str);
    return str;
}