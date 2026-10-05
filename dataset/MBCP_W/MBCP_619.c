void moveNum(char *str) {
    char *result = (char *)malloc(sizeof(char) * 1000);
    char *numbers = (char *)malloc(sizeof(char) * 1000);
    
    int numbersIndex = 0;
    int resultIndex = 0;
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
