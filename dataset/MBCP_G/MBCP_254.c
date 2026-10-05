void wordsAe(char *text, char result[][50], int *count) {
    char *token;
    char delimiters[] = " ";
    *count = 0;
    token = strtok(text, delimiters);
    while (token != NULL) {
        if (tolower(token[0]) == 'a' || tolower(token[0]) == 'e') {
            strcpy(result[*count], token);
            (*count)++;
        }
        token = strtok(NULL, delimiters);
    }
}