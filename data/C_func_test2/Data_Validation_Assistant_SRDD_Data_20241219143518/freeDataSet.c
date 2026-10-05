void freeDataSet(DataSet *dataSet) {
    if (!dataSet) return;
    for (size_t i = 0; i < dataSet->size; i++) {
        free(dataSet->data[i]);
    }
    free(dataSet->data);
    free(dataSet);
}