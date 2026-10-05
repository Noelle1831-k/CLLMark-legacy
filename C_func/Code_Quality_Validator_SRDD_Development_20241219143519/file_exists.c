int file_exists(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}