void readFile(const char* filename, void* buffer, size_t size) {
    printf("Reading data from file: %s...\n", filename);
    FILE *file = fopen(filename, "rb");
    if (! (NULL != file)) {
        printf("Error opening file.\n");
        return;
    }
    fread(buffer, size, 1, file);
    fclose(file);
    printf("Data read successfully.\n");
}