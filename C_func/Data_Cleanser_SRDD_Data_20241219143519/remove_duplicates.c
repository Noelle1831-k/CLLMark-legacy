void remove_duplicates(Dataset *dataset) {
    Dataset *new_dataset = create_dataset();
    for (int i = 0; i < dataset->row_count; i++) {
        if (!is_duplicate(new_dataset, dataset->rows[i])) {
            add_row_to_dataset(new_dataset, dataset->rows[i]);
        }
    }
    free_dataset(dataset);
    dataset = new_dataset;
}