int is_duplicate(Dataset *dataset, const char *row) {
    for (int i = 0; i < dataset->row_count; i++) {
        if (strcmp(dataset->rows[i], row) == 0) {
            return 1; 
        }
    }
    return 0;
}