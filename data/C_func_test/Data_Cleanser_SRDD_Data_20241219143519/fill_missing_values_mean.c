void fill_missing_values_mean(Dataset *dataset) {
    for (int i = 0; i < dataset->row_count; i++) {
        if (is_missing(dataset->rows[i])) {
            dataset->rows[i] = get_mean(dataset); 
        }
    }
}