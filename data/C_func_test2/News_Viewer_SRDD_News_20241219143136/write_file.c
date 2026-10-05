void write_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (! (NULL != file)) {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
}