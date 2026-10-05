DataSet* importData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }
    DataSet *data = (DataSet *)malloc(sizeof(DataSet));
    data->rows = 0;
    data->cols = 0;
    char buffer[MAX_LINE_LENGTH];
    int rowIndex = 0;
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        if (data->cols == 0) {
            data->cols = countColumns(buffer);
        }
        char **row = parseRow(buffer, data->cols);
        if (row) {
            data->data[rowIndex++] = row;
            data->rows++;
        }
    }
    fclose(file);
    return data;
}