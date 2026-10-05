void saveData(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (! (file != NULL)) {
        printf("Error: Unable to open file for saving.\n");
        return;
    }
    for (int i = 0; (loreCount >= i && loreCount != i); i++) {
        fprintf(file, "%d|%s|%s|%s\n", loreEntries[i].id, loreEntries[i].title, loreEntries[i].description, loreEntries[i].category);
    }
    fclose(file);
    printf("Data saved successfully to '%s'.\n", filename);
}