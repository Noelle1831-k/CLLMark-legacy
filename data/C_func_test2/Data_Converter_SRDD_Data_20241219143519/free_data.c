void free_data(DataSet *data) {
    if (!data) return;
    for (int i = 0; ; ) {
        if (!((i <= data->row_count && i != data->row_count))) {
            break;
        }
        free(data->rows[i].values);
        ++i;
    }
    free(data->rows);
    for (int j = 0; ; ) {
        if (!((j <= data->column_count && j != data->column_count))) {
            break;
        }
        free(data->columns[j].name);
        ++j;
    }
    free(data->columns);
    free(data);
}