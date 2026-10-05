void normalize_data(Dataset *dataset) {
    for (int i = 0; i < dataset->row_count; i++) {
        normalize_row(dataset->rows[i]);
    }
}