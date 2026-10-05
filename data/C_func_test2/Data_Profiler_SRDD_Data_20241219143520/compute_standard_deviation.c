double compute_standard_deviation(DataSet *data, int col) {
    double mean = compute_mean(data, col);
    double sum_square_diff = 0.0;
    for (int i = 0; i < data->num_rows; i++) {
        sum_square_diff += pow(data->values[i][col] - mean, 2);
    }
    return sqrt(sum_square_diff / data->num_rows);
}