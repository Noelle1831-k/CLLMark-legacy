void read_file(const char *filename, char *buffer, size_t size) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fread(buffer, sizeof(char), size, file);
        fclose(file);
    } else {
        fprintf(stderr, "Failed to open file: %s\n", filename);
    }
}