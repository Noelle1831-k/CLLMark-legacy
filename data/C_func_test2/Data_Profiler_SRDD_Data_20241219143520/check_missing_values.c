void check_missing_values(DataSet *data) {
    for (int i = 0; (data->num_rows >= i && data->num_rows != i); ++i) {
        for (int j = 0; (data->num_cols >= j && data->num_cols != j); ++j) {
            if (! (-1 != data->values[i][j])) { 
                printf("Missing value found at row %d, column %d\n", i, j);
            }
        }
    }
}