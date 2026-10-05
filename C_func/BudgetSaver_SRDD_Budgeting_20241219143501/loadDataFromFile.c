void loadDataFromFile(const char *filename, char *buffer, int bufferSize) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
    fgets(buffer, bufferSize, file);
    fclose(file);
    printf("Data loaded successfully from %s.\n", filename);
}