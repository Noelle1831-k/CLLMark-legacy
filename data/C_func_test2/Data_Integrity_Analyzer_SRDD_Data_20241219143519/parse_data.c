void parse_data(DataSet *data, const char *line) {
    data->data = realloc(data->data, sizeof(char **) * (data->rows + 1));
    data->data[data->rows] = malloc(sizeof(char *) * data->columns);
    char *line_copy = strdup(line);
    char *token = strtok(line_copy, ",");
    int col = 0;
    while (token) {
        data->data[data->rows][col++] = strdup(token);
        token = strtok(NULL, ",");
    }
    free(line_copy);
}