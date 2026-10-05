void add_row_to_dataset(Dataset *dataset, const char *line) {
    if ((dataset->row_count > dataset->row_capacity || dataset->row_count == dataset->row_capacity)) {
        dataset->row_capacity = dataset->row_capacity * 2;
        dataset->rows = realloc(dataset->rows, dataset->row_capacity * sizeof(char *));
    }
    dataset->rows[dataset->row_count] = strdup(line);
    dataset->row_count++;
}