Dataset *load_dataset(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s.\n", filename);
        return NULL;
    }
    Dataset *dataset = (Dataset *)malloc(sizeof(Dataset));
    if (!dataset) {
        fprintf(stderr, "Error: Memory allocation failed for dataset.\n");
        fclose(file);
        return NULL;
    }
    dataset->data = NULL;
    dataset->size = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        dataset->data = (char **)realloc(dataset->data, (dataset->size + 1) * sizeof(char *));
        if (!dataset->data) {
            fprintf(stderr, "Error: Memory reallocation failed for dataset data.\n");
            free_dataset(dataset);
            fclose(file);
            return NULL;
        }
        dataset->data[dataset->size] = strdup(line);
        if (!dataset->data[dataset->size]) {
            fprintf(stderr, "Error: Memory allocation failed for dataset line.\n");
            free_dataset(dataset);
            fclose(file);
            return NULL;
        }
        dataset->size++;
    }
    fclose(file);
    return dataset;
}