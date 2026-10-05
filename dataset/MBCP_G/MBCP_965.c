char* camelToSnake(const char* text) {
    int length = strlen(text);
    int snakeLength = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(text[i])) {
            snakeLength += 2; 
        } else {
            snakeLength++;
        }
    }
    char* snakeStr = (char*)malloc(snakeLength + 1);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(text[i])) {
            if (i > 0) {
                snakeStr[j++] = '_';
            }
            snakeStr[j++] = tolower(text[i]);
        } else {
            snakeStr[j++] = text[i];
        }
    }
    snakeStr[j] = '\0';
    return snakeStr;
}