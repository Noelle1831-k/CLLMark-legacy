Dataset* loadDataset(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filePath);
        return NULL;
    }
    Dataset *dataset = (Dataset*)malloc(sizeof(Dataset));
    if (!dataset) {
        fprintf(stderr, "Error: Memory allocation failed for dataset.\n");
        fclose(file);
        return NULL;
    }
    dataset->records = NULL;
    dataset->recordCount = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        parseDataset(dataset, line);
    }
    fclose(file);
    return dataset;
}