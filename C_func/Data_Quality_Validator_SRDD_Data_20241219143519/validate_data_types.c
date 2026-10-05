void validate_data_types(const char *filename) {
    printf("Validating data types in dataset: %s...\n", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    char line[1024];
    int row_count = 0;
    int type_mismatch_count = 0;
    while (fgets(line, sizeof(line), file)) {
        row_count++;
        char *token = strtok(line, ",");
        while (token) {
            if (strchr(token, '.') != NULL) {  
                if (strspn(token, "0123456789.") != strlen(token)) {
                    type_mismatch_count++;
                    break;
                }
            }
            token = strtok(NULL, ",");
        }
    }
    printf("Validation complete. Found %d type mismatches in %d rows.\n", type_mismatch_count, row_count);
    fclose(file);
}