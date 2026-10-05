void saveDataToFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data saved successfully to %s.\n", filename);
}