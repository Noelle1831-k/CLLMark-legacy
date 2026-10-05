int readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        return 0;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    return 1;
}