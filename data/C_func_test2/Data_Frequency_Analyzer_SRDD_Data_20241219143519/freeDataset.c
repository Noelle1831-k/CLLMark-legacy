void freeDataset(Dataset *dataset) {
    for (int i = 0; i < dataset->size; i++) {
        for (int j = 0; j < dataset->numColumns; j++) {
            free(dataset->data[i][j]);
        }
        free(dataset->data[i]);
    }
    free(dataset->data);
    for (int i = 0; i < dataset->numColumns; i++) {
        free(dataset->columnNames[i]);
    }
    free(dataset->columnNames);
}