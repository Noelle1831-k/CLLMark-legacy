void read_file(const char *path, char **buffer) {
    FILE *file = fopen(path, "r");
    if (!file) {
        log_error("Unable to open file for reading.");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    *buffer = (char *)malloc((file_size + 1) * sizeof(char));
    if (!*buffer) {
        log_error("Memory allocation failed for file reading.");
        fclose(file);
        exit(1);
    }
    fread(*buffer, sizeof(char), file_size, file);
    (*buffer)[file_size] = '\0'; 
    fclose(file);
}