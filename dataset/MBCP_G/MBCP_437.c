void removeOdd(char *str) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 != 0) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}