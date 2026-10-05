int import_dataset(const char *filename, double dataset[][MAX_VARIABLES], int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }
    char line[MAX_LINE_LENGTH];
    *rows = 0;
    *cols = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int col_index = 0;
        while (token) {
            dataset[*rows][col_index++] = atof(token);
            token = strtok(NULL, ",");
        }
        if (*cols == 0) {
            *cols = col_index;
        }
        (*rows)++;
    }
    fclose(file);
    return 1;
}