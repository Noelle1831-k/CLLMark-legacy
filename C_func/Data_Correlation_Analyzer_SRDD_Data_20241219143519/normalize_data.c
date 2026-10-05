void normalize_data() {
    printf("Normalizing data...\n");
    for (int col = 0; col < num_columns; col++) {
        float mean = calculate_mean(dataset, num_rows, col);
        float stddev = calculate_standard_deviation(dataset, num_rows, col);
        for (int row = 0; row < num_rows; row++) {
            dataset[row][col] = (dataset[row][col] - mean) / stddev;
        }
    }
    printf("Data normalization complete.\n");
}