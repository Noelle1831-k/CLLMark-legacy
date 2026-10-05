void parseLine(char *line, double *rowData, int cols) {
    char *token = strtok(line, ",");
    for (int i = 0; i < cols && token != NULL; i++) {
        rowData[i] = atof(token);
        token = strtok(NULL, ",");
    }
}