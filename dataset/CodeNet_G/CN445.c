void countJOIandIOI(const char *str, int *joiCount, int *ioiCount) {
    int len = strlen(str);
    *joiCount = 0;
    *ioiCount = 0;
    for (int i = 0; i < len - 2; i++) {
        if (str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            (*joiCount)++;
        }
        if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            (*ioiCount)++;
        }
    }
}