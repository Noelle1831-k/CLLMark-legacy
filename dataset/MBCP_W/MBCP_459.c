void removeUppercase(char *str) {
    char *result = (char *)malloc(sizeof(char) * strlen(str) + 1);
    int j = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (!isupper(str[i])) {
            result[j++] = str[i];
        } else {
            while (isupper(str[i])) {
                i++;
            }
            i--; 
        }
        i++;
    }
    result[j] = '\0';
    strcpy(str, result);
}