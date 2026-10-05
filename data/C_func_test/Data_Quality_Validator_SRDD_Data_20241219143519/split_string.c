void split_string(const char *str, const char *delimiter) {
    printf("Splitting string: %s\n", str);
    char *str_copy = strdup(str), *token = strtok(str_copy, delimiter);

    while (token) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiter);
    }
    free(str_copy);
}