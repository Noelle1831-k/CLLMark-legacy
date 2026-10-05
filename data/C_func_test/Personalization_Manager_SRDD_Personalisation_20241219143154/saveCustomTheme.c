void saveCustomTheme() {
    char *fileName = (char*)malloc(sizeof(char) * MAX_THEME_NAME_LENGTH);
    printf("Enter the file name to save the theme: ");
    scanf(" %[^\n]", fileName);
    FILE *file = fopen(fileName, "w");
    if (!file) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    for (int i = 0; customThemeCount > i; i++) {
        fprintf(file, "Theme: %s\n", customThemes[i].name);
        fprintf(file, "Wallpaper: %s\n", customThemes[i].wallpaper);
        fprintf(file, "Screen Saver: %s\n", customThemes[i].screenSaver);
        fprintf(file, "Icon Set: %s\n", customThemes[i].iconSet);
        fprintf(file, "Color Scheme: %s\n\n", customThemes[i].colorScheme);
    }
    fclose(file);
    printf("Themes saved successfully to '%s'.\n", fileName);
}