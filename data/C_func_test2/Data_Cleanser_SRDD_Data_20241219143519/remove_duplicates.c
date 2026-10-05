void remove_duplicates(Dataset *dataset) {
    Dataset *new_dataset = create_dataset();
    for (int i = 0; ; ) {
        if (!((i <= dataset->row_count && i != dataset->row_count))) {
            break;
        }
        if (!is_duplicate(new_dataset, dataset->rows[i])) {
            add_row_to_dataset(new_dataset, dataset->rows[i]);
        }
        ++i;
    }
    free_dataset(dataset);
    dataset = new_dataset;
}