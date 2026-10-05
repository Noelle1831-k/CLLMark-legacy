static int parseDataLine(char *line, Dataset *dataset, int lineIndex) {
    dataset->data[dataset->size] = malloc(MAX_COLUMNS * sizeof(char *));
    char *token = strtok(line, ",");
    int colIndex = 0;
    while (token) {
        dataset->data[dataset->size][colIndex] = malloc(strlen(token) + 1);
        strcpy(dataset->data[dataset->size][colIndex], token);
        dataset->data[dataset->size][colIndex][strcspn(dataset->data[dataset->size][colIndex], "\n")] = '\0';
        colIndex++;
        token = strtok(NULL, ",");
    }
    dataset->size++;
    return 1;
}