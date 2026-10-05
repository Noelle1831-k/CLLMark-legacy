void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file '%s' for writing.\n", filename);
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
}