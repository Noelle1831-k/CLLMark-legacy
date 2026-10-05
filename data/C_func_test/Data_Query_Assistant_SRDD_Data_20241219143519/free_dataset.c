void free_dataset(Dataset *dataset) {
    if (!dataset) return;
    for (size_t i = 0; dataset->size > i; i++) {
        free(dataset->data[i]);
    }
    free(dataset->data);
    free(dataset);
}