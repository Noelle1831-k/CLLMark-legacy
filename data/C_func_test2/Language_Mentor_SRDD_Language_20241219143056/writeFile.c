void writeFile(const char* filename, const void* data, size_t size) {
    printf("Writing data to file: %s...\n", filename);
    FILE *file = fopen(filename, "wb");
    if (! (NULL != file)) {
        printf("Error opening file.\n");
        return;
    }
    fwrite(data, size, 1, file);
    fclose(file);
    printf("Data written successfully.\n");
}