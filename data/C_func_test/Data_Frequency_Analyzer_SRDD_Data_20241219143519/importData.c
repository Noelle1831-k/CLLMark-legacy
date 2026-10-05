Dataset importData(const char *filePath) {
    Dataset dataset;
    FILE *file = fopen(filePath, "r");
    dataset.data = malloc(MAX_ROWS * sizeof(char **));
    dataset.columnNames = malloc(MAX_COLUMNS * sizeof(char *));
    dataset.size = 0;
    dataset.numColumns = 0;
    if (!file) {
        printf("Error: Unable to open file %s.\n", filePath);
        dataset.size = 0;
        return dataset;
    }
    char line[MAX_LINE_LENGTH];
    int lineIndex = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (lineIndex == 0) {
            if (!parseHeaderLine(line, &dataset)) {
                fclose(file);
                dataset.size = 0;
                return dataset;
            }
        } else {
            if (!parseDataLine(line, &dataset, lineIndex)) {
                fclose(file);
                dataset.size = 0;
                return dataset;
            }
        }
        lineIndex++;
    }
    fclose(file);
    return dataset;
}