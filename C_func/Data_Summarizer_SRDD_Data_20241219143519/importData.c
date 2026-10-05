int importData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 0;
    }
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        parseLine(line);
    }
    fclose(file);
    return 1;
}