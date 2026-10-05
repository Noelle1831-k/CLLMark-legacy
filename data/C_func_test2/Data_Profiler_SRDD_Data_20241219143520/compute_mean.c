double compute_mean(DataSet *data, int col) {
    double sum = 0.0;
    for (int i = 0; i < data->num_rows; i++) {
        sum += data->values[i][col];
    }
    return sum / data->num_rows;
}