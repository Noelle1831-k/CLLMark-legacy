void freeDataSet(DataSet *data) {
    if (!data) return;
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data);
}