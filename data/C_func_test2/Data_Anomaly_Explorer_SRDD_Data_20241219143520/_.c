double **loadCSV(char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handleError("Error opening file.");
        return NULL;
    }
    char line[MAX_LINE_LENGTH];
    int rowCount = 0, colCount = 0;
    double **data = NULL;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (rowCount == 0) {
            char *token = strtok(line, ",");
            while (token != NULL) {
                colCount++;
                token = strtok(NULL, ",");
            }
            data = allocate2DArray(1000, colCount); 
        } else {
            double *rowData = malloc(colCount * sizeof(double));
            parseLine(line, rowData, colCount);
            for (int i = 0; i < colCount; i++) {
                data[rowCount - 1][i] = rowData[i];
            }
            free(rowData);
        }
        rowCount++;
    }
    fclose(file);
    *rows = rowCount - 1;
    *cols = colCount;
    return data;
}