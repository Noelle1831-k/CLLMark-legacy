void parseCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printError("Failed to open data file.");
        return;
    }
    char line[1024];
    numRows = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int column = 0;
        while (token) {
            dataset[numRows][column++] = atof(token);
            token = strtok(NULL, ",");
        }
        if (numColumns == 0) {
            numColumns = column;
        }
        numRows++;
        if (numRows >= MAX_ROWS) {
            printError("Maximum number of rows exceeded.");
            break;
        }
    }
    fclose(file);
}