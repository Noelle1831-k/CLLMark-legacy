void handle_file_import(char *filename) {
    if (validate_csv(filename)) {
        printf("File '%s' imported successfully.\n", filename);
    } else {
        printf("File validation failed. Please check the file path or format.\n");
    }
}