int checkConcat(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len2 == 0 || len1 % len2 != 0) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i % len2]) {
            return 0;
        }
    }
    return 1;
}