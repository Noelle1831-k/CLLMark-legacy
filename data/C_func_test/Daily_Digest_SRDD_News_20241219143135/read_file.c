void read_file(const char *filename, char *buffer, size_t buffer_size) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fread(buffer, 1, buffer_size, file);
        fclose(file);
    }
}