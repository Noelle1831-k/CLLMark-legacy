void read_file(const char *filename, char ****data, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        *rows = 0;
        *cols = 0;
        return;
    }
    char buffer[1024];
    int row_count = 0, col_count = 0;
    char ***dataset = NULL;
    while (fgets(buffer, sizeof(buffer), file)) {
        char **row = NULL;
        int count = 0;
        split_string(buffer, ',', &row, &count);
        if (row_count == 0) {
            col_count = count;
        }
        dataset = (char ***)realloc(dataset, (row_count + 1) * sizeof(char **));
        dataset[row_count++] = row;
    }
    fclose(file);
    *data = dataset;
    *rows = row_count;
    *cols = col_count;
}