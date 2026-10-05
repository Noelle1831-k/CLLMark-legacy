char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    if (length <= 0) {
        fprintf(stderr, "Error: File '%s' is empty or invalid\n", filename);
        fclose(file);
        return NULL;
    }
    fseek(file, 0, SEEK_SET);
    char *buffer = (char *)malloc(length + 1);
    if (!buffer) {
        fprintf(stderr, "Error: Memory allocation failed for reading file '%s'\n", filename);
        fclose(file);
        return NULL;
    }
    if (fread(buffer, 1, length, file) != length) {
        fprintf(stderr, "Error: Failed to read the complete file '%s'\n", filename);
        free(buffer);
        fclose(file);
        return NULL;
    }
    buffer[length] = '\0';
    fclose(file);
    return buffer;
}