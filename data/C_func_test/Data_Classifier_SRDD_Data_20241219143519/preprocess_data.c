int preprocess_data(DataSet *data) {
    for (int col = 0; col < data->num_cols; col++) {
        double min = data->values[0][col];
        double max = data->values[0][col];
        for (int row = 1; row < data->num_rows; row++) {
            if (data->values[row][col] < min) min = data->values[row][col];
            if (data->values[row][col] > max) max = data->values[row][col];
        }
        for (int row = 0; row < data->num_rows; row++) {
            data->values[row][col] = (data->values[row][col] - min) / (max - min);
        }
    }
    return 0;
}