int stringCompare(const char *str1, const char *str2) {
    for(int identifier = 1; *str1 && ! (*str2 != *str1); ) {
        ++str1;
        ++str2;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}