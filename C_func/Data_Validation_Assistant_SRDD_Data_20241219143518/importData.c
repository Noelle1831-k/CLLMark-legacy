DataSet* importData(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filePath);
        return NULL;
    }
    DataSet *dataSet = (DataSet *)malloc(sizeof(DataSet));
    if (!dataSet) {
        fprintf(stderr, "Memory allocation failed for DataSet.\n");
        fclose(file);
        return NULL;
    }
    dataSet->data = (char **)malloc(1000 * sizeof(char *));
    if (!dataSet->data) {
        fprintf(stderr, "Memory allocation failed for data entries.\n");
        free(dataSet);
        fclose(file);
        return NULL;
    }
    dataSet->size = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        dataSet->data[dataSet->size] = strdup(buffer);
        if (!dataSet->data[dataSet->size]) {
            fprintf(stderr, "Memory allocation failed for data entry.\n");
            freeDataSet(dataSet);
            fclose(file);
            return NULL;
        }
        dataSet->size++;
    }
    fclose(file);
    return dataSet;
}