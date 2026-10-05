void save_to_file(const char* filename, const char* data) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not save data to file.\n");
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data saved successfully to %s.\n", filename);
}