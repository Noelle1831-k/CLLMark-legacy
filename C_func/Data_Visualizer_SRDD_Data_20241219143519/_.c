char** parseRow(const char *line, int cols) {
    char **row = (char **)malloc(cols * sizeof(char *));
    char *copy = strdup(line);
    char *token = strtok(copy, ",");
    int i = 0;
    while (token) {
        row[i++] = strdup(token);
        token = strtok(NULL, ",");
    }
    free(copy);
    return row;
}