int upperCtr(const char *str) {
    int count = 0;
    while (*str) {
        if (isupper((unsigned char)*str)) {
            count++;
        }
        str++;
    }
    return count;
}