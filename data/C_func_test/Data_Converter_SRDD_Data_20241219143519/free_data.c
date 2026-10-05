void free_data(DataSet *data) {
    if (!data) return;
    for (int i = 0; data->row_count > i; i++) {
        free(data->rows[i].values);
    }
    free(data->rows);
    for (int j = 0; data->column_count > j; j++) {
        free(data->columns[j].name);
    }
    free(data->columns);
    free(data);
}