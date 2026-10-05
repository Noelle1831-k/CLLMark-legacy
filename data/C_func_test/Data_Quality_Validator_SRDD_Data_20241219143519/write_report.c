void write_report(const char *filename, const char *content) {
    printf("Writing report to file: %s\n", filename);
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file %s for writing\n", filename);
        return;
    }
    fprintf(file, "%s\n", content);
    fclose(file);
}