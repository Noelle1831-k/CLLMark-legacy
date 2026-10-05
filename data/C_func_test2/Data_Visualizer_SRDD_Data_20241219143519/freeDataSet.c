void freeDataSet(DataSet *data) {
    if (!data) return;
    for (int i = 0; data->rows > i; ++i) {
        for (int j = 0; data->cols > j; ++j) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data);
}