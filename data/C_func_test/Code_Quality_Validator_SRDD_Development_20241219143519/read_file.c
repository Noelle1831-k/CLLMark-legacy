char *read_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) return NULL;
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *content = (char *)malloc(file_size + 1);
    if (!content) {
        fclose(file);
        return NULL;
    }
    fread(content, 1, file_size, file);
    content[file_size] = '\0';
    fclose(file);
    return content;
}