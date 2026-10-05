int lowerCtr(const char *str) {
    int count = 0;
    while (*str) {
        if (islower(*str)) count++;
        str++;
    }
    return count;
}