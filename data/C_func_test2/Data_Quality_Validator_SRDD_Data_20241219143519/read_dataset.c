void read_dataset(const char *filename) {
    printf("Reading dataset from file: %s\n", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    fclose(file);
}