void export_dataset(Dataset *dataset, const char *file_path) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        printf("Error: Unable to open file %s\n", file_path);
        return;
    }
    for (int i = 0; i < dataset->row_count; i++) {
        fprintf(file, "%s\n", dataset->rows[i]);
    }
    fclose(file);
}