void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fwrite(content, sizeof(char), strlen(content), file);
        fclose(file);
    }
}