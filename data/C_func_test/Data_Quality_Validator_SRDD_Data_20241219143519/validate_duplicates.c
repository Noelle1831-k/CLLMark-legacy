void validate_duplicates(const char *filename) {
    printf("Validating duplicates in dataset: %s...\n", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    char line[1024];
    int row_count = 0;
    char *lines[1000];  
    int duplicate_count = 0;
    while (fgets(line, sizeof(line), file)) {
        row_count++;
        int is_duplicate = 0;
        for (int i = 0; i < row_count - 1; i++) {
            if (strcmp(lines[i], line) == 0) {
                is_duplicate = 1;
                break;
            }
        }
        if (is_duplicate) {
            duplicate_count++;
        } else {
            lines[row_count - 1] = strdup(line);
        }
    }
    printf("Validation complete. Found %d duplicates in %d rows.\n", duplicate_count, row_count);
    fclose(file);
}