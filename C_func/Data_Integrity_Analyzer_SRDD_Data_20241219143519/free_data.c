void free_data(DataSet *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}