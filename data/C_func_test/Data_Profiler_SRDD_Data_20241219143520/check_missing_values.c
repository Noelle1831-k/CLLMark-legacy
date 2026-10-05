void check_missing_values(DataSet *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            if (data->values[i][j] == -1) { 
                printf("Missing value found at row %d, column %d\n", i, j);
            }
        }
    }
}