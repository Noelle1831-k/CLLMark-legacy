void write_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    fputs(content, file);
    fclose(file);
}