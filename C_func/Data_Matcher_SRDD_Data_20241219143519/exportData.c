void exportData(MatchedRecords *matches, const char *filePath) {
    FILE *file = fopen(filePath, "w");
    if (!file) {
        fprintf(stderr, "Error: Failed to open export file %s\n", filePath);
        return;
    }
    for (int i = 0; i < matches->count; i++) {
        for (int j = 0; j < FIELD_COUNT; j++) {
            fprintf(file, "%s,", matches->records[i].fields[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Data exported successfully to %s\n", filePath);
}