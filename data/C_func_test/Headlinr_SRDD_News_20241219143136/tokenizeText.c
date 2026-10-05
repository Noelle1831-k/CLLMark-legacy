void tokenizeText(char *text) {
    printf("Tokenizing text: %s\n", text);
    char *token = strtok(text, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }
}