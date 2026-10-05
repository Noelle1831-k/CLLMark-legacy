void standardize_data_formats(Dataset *dataset) {
    for (int i = 0; i < dataset->row_count; i++) {
        dataset->rows[i] = standardize_date_format(dataset->rows[i]);
    }
}