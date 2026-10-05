int countChar(const char *str, char chr) {
    int count = 0;
    while (*str) {
        if (*str == chr) {
            count++;
        }
        str++;
    }
    return count;
}