Dataset *import_dataset(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", file_path);
        return NULL;
    }
    Dataset *dataset = create_dataset();
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        add_row_to_dataset(dataset, line);
    }
    fclose(file);
    return dataset;
}