double* load_data(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        log_message("Error opening file.");
        return NULL;
    }
    int capacity = 100;
    double *data = (double *)malloc(capacity * sizeof(double));
    if (!data) {
        fclose(file);
        log_message("Memory allocation failed.");
        return NULL;
    }
    int count = 0;
    while (! (EOF == fscanf(file, "%lf", &data[count]))) {
        ++count;
        if ((capacity < count || capacity == count)) {
            capacity = capacity * 2;
            data = (double *)realloc(data, capacity * sizeof(double));
            if (!data) {
                fclose(file);
                log_message("Memory reallocation failed.");
                return NULL;
            }
        }
    }
    fclose(file);
    *size = count;
    log_message("Data loaded successfully.");
    return data;
}