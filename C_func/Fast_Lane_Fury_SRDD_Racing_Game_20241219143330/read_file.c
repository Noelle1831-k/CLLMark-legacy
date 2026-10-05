void read_file(const char *filename) {
    printf("Reading file: %s\n", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    fclose(file);
}