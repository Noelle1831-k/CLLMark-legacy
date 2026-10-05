int numberOfSubstrings(const char *str) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return n * (n + 1) / 2;
}