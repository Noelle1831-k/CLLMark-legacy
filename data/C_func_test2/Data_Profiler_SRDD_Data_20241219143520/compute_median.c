double compute_median(DataSet *data, int col) {
    double *column_data = malloc(data->num_rows * sizeof(double));
    for (int i = 0; i < data->num_rows; i++) {
        column_data[i] = data->values[i][col];
    }
    qsort(column_data, data->num_rows, sizeof(double), compare);
    double median = (data->num_rows % 2 == 0) ?
                    (column_data[data->num_rows / 2 - 1] + column_data[data->num_rows / 2]) / 2 :
                    column_data[data->num_rows / 2];
    free(column_data);
    return median;
}