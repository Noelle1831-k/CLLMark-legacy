void detect_outliers_zscore(DataSet *data) {
    for (int col = 0; col < data->num_cols; col++) {
        double mean = compute_mean(data, col);
        double std_dev = compute_standard_deviation(data, col);
        for (int row = 0; row < data->num_rows; row++) {
            double zscore = (data->values[row][col] - mean) / std_dev;
            if (fabs(zscore) > 3) {
                printf("Outlier detected at row %d, column %d with Z-score: %.2f\n", row, col, zscore);
            }
        }
    }
}