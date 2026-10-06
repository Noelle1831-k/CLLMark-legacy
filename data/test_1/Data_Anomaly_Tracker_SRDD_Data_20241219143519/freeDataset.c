void freeDataset(Dataset *dataset) {
    if (dataset) {
        free(dataset);
    }
}