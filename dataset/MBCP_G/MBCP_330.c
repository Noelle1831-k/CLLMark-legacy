int is_valid_word(const char *word) {
    int len = strlen(word);
    return (len == 3 || len == 4 || len == 5);
}
void findChar(const char *text, char result[][6], int *count) {
    const char *delimiter = " ";
    char temp[100];
    strcpy(temp, text);
    char *token = strtok(temp, delimiter);
    *count = 0;
    while (token != NULL) {
        if (is_valid_word(token)) {
            strcpy(result[*count], token);
            (*count)++;
        }
        token = strtok(NULL, delimiter);
    }
}