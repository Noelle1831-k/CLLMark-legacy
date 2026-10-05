void split_string(const char *str, char delimiter, char ***tokens, int *count) {
    char *copy = strdup(str);
    char *token = strtok(copy, &delimiter);
    char **result = NULL;
    int index = 0;
    while (token) {
        result = (char **)realloc(result, (index + 1) * sizeof(char *));
        *(result + index++) = strdup(token);
        token = strtok(NULL, &delimiter);
    }
    free(copy);
    *tokens = result;
    *count = index;
}