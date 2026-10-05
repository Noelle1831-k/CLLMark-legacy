DataSet* load_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }
    DataSet *data = malloc(sizeof(DataSet));
    if (data == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }
    data->values = NULL;
    data->num_rows = 0;
    data->num_cols = 0;
    if (!read_csv(file, data)) {
        printf("Error: Failed to read data from file %s\n", filename);
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    return data;
}