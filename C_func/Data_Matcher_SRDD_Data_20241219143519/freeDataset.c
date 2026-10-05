void freeDataset(Dataset *dataset) {
    if (dataset) {
        free(dataset->records);
        free(dataset);
    }
}