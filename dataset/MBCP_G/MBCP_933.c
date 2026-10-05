char* camelToSnake(const char* text) {
    int len = strlen(text);
    int new_len = len;
    for (int i = 0; i < len; ++i) {
        if (isupper(text[i])) {
            new_len++;
        }
    }
    char* snake_case = (char*)malloc(sizeof(char) * (new_len + 1));
    if (snake_case == NULL) {
        return NULL; 
    }
    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (isupper(text[i])) {
            if (i != 0) {
                snake_case[j++] = '_';
            }
            snake_case[j++] = tolower(text[i]);
        } else {
            snake_case[j++] = text[i];
        }
    }
    snake_case[j] = '\0';
    return snake_case;
}