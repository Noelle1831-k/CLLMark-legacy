void free_data(DataSet *data) {
    if (data) {
        for (int i = 0; i < data->num_rows; i++) {
            free(data->values[i]);
        }
        free(data->values);
        free(data);
    }
}