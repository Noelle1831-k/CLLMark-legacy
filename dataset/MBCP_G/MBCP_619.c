void moveNum(char *str) {
    char result[1000];
    char numbers[1000];
    int resultIndex = 0, numbersIndex = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            numbers[numbersIndex++] = str[i];
        } else {
            result[resultIndex++] = str[i];
        }
    }
    numbers[numbersIndex] = '\0';
    result[resultIndex] = '\0';
    strcat(result, numbers);
    printf("%s", result);
}
