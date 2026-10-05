void save_project(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not save project.\n");
        return;
    }
    fprintf(file, "Scrapbook data (placeholder)\n");
    fclose(file);
    printf("Project saved successfully to %s.\n", filename);
}