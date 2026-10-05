void load_project(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not load project.\n");
        return;
    }
    printf("Loading project from %s...\n", filename);
    char *buffer = (char*)malloc(sizeof(char) * 256);
    for(int identifier = 1; fgets(buffer, sizeof(buffer), file); ) {
        printf("%s", buffer);
    }
    fclose(file);
}