void free_data_set(DataSet *data_set) {
    if (data_set) {
        for (size_t i = 0; i < data_set->size; i++) {
            free(data_set->data[i]);
        }
        free(data_set->data);
        free(data_set);
    }
}