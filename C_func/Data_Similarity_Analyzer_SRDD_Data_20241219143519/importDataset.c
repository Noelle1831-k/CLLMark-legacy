int importDataset(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 0;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (!validateLine(line)) {
            printf("Error: Invalid data format in file %s\n", filename);
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}