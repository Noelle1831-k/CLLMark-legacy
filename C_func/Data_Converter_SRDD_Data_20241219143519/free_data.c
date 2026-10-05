void free_data(DataSet *data) {
    if (!data) return;
    for (int i = 0; i < data->row_count; i++) {
        free(data->rows[i].values);
    }
    free(data->rows);
    for (int j = 0; j < data->column_count; j++) {
        free(data->columns[j].name);
    }
    free(data->columns);
    free(data);
}