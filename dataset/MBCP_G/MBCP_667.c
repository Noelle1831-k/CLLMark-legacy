int checkVow(const char *str, const char *vowels) {
    int count = 0;
    while (*str) {
        if (strchr(vowels, *str)) {
            count++;
        }
        str++;
    }
    return count;
}