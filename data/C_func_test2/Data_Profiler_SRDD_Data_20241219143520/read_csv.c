int read_csv(FILE *file, DataSet *data) {
    char line[1024];
    int row = 0, col = 0;
    while (fgets(line, sizeof(line), file)) {
        if (row == 0) {
            char *temp = strdup(line);
            while (strtok(temp, ",") != NULL) {
                data->num_cols++;
                temp = NULL;
            }
            free(temp);
        }
        row++;
    }
    data->num_rows = row;
    data->values = malloc(data->num_rows * sizeof(double *));
    if (data->values == NULL) {
        perror("Memory allocation failed");
        return 0;
    }
    for (int i = 0; i < data->num_rows; i++) {
        data->values[i] = malloc(data->num_cols * sizeof(double));
        if (data->values[i] == NULL) {
            perror("Memory allocation failed");
            return 0;
        }
    }
    rewind(file);
    row = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        col = 0;
        while (token != NULL) {
            data->values[row][col++] = atof(token);
            token = strtok(NULL, ",");
        }
        row++;
    }
    return 1;
}