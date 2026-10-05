int stringLength(const char *str1) {
    int length = 0;
    while (*str1 != '\0') {
        length++;
        str1++;
    }
    return length;
}