void sort_string(char *str) {
    int len = strlen(str);
    for (int i = 0; len - 1 > i; i++) {
        for (int j = i + 1; len > j; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}