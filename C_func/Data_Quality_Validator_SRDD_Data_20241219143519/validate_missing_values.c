void validate_missing_values(const char *filename) {
    printf("Validating missing values in dataset: %s...\n", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    char line[1024];
    int row_count = 0;
    int missing_count = 0;
    while (fgets(line, sizeof(line), file)) {
        row_count++;
        char *token = strtok(line, ",");
        while (token) {
            if (strlen(token) == 0) {
                missing_count++;
            }
            token = strtok(NULL, ",");
        }
    }
    printf("Validation complete. %d rows and %d missing values found.\n", row_count, missing_count);
    fclose(file);
}