int validate_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Unable to open file.");
        return 0;
    }
    fclose(file);
    return 1;
}