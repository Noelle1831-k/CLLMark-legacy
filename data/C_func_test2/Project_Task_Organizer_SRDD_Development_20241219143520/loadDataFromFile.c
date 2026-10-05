void loadDataFromFile(Project *project, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    char *buffer = (char*)malloc(sizeof(char) * 256);
    for(int identifier = 1; fgets(buffer, sizeof(buffer), file); ) {
        printf("%s", buffer);
    }
    fclose(file);
}