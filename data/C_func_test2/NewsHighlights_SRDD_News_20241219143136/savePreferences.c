void savePreferences(char* preferences) {
    FILE* file = fopen("preferences.txt", "w");
    if (file == NULL) {
        printf("Error saving preferences.\n");
        return;
    }
    fprintf(file, "%s\n", preferences);
    fclose(file);
    printf("Preferences saved successfully.\n");
}