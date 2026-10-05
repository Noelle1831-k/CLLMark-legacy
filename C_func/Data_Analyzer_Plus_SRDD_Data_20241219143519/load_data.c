double *load_data(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }
    int capacity = 10;
    double *data = (double *)malloc(capacity * sizeof(double));
    if (!data) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return NULL;
    }
    *size = 0;
    while (fscanf(file, "%lf", &data[*size]) == 1) {
        (*size)++;
        if (*size >= capacity) {
            capacity *= 2;
            double *temp = (double *)realloc(data, capacity * sizeof(double));
            if (!temp) {
                printf("Error: Memory reallocation failed\n");
                free(data);
                fclose(file);
                return NULL;
            }
            data = temp;
        }
    }
    fclose(file);
    if (*size == 0) {
        printf("Error: No data found in the file.\n");
        free(data);
        return NULL;
    }
    return data;
}