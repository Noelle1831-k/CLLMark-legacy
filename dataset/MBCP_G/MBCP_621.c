void incrementNumerics(char **testList, int size, int k) {
    for (int i = 0; i < size; i++) {
        char *str = testList[i];
        int isNumeric = 1;
        for (int j = 0; j < strlen(str); j++) {
            if (!isdigit(str[j])) {
                isNumeric = 0;
                break;
            }
        }
        if (isNumeric) {
            int num = atoi(str);
            num += k;
            int length = snprintf(NULL, 0, "%d", num);
            char *newStr = malloc(length + 1);
            snprintf(newStr, length + 1, "%d", num);
            testList[i] = newStr;
        }
    }
}