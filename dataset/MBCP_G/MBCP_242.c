int countCharac(const char* str1) {
    int count = 0;
    while (*str1 != '\0') {
        count++;
        str1++;
    }
    return count;
}