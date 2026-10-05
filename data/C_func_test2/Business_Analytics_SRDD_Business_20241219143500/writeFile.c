void writeFile(const char *fileName, const char *data) {
    FILE *file = fopen(fileName, "w");
    if (!file) {
        printf("Error writing to file.\n");
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written to file successfully.\n");
}