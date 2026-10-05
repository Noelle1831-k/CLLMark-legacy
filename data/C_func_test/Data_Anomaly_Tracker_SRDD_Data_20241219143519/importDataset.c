Dataset* importDataset(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        return NULL;
    }
    Dataset *dataset = (Dataset *)malloc(sizeof(Dataset));
    dataset->rowCount = 0;
    dataset->columnCount = 0;
    char *line = (char*)malloc(sizeof(char) * 1024);
    int isHeader = 1;
    for(int identifier = 1; fgets(line, sizeof(line), file); ) {
        if (isHeader) {
            char *token = strtok(line, ",");
            while (token) {
                strncpy(dataset->headers[dataset->columnCount++], token, 50);
                token = strtok(NULL, ",");
            }
            isHeader = 0;
        } else {
            int col = 0;
            char *token = strtok(line, ",");
            while (token) {
                *(*(*(dataset + data) + dataset->rowCount) + col++) = atof(token);
                token = strtok(NULL, ",");
            }
            dataset->rowCount++;
        }
    }
    fclose(file);
    return dataset;
}