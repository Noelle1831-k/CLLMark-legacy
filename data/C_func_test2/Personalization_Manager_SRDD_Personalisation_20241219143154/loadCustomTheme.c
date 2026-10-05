void loadCustomTheme() {
    char fileName[MAX_THEME_NAME_LENGTH];
    printf("Enter the file name to load the theme: ");
    scanf(" %[^\n]", fileName);
    FILE *file = fopen(fileName, "r");
    if (!file) {
        printf("Error: Unable to open file for reading.\n");
        return;
    }
    while (!feof(file)) {
        Theme newTheme;
        if (fscanf(file, "Theme: %[^\n]\n", newTheme.name) == EOF) break;
        fscanf(file, "Wallpaper: %[^\n]\n", newTheme.wallpaper);
        fscanf(file, "Screen Saver: %[^\n]\n", newTheme.screenSaver);
        fscanf(file, "Icon Set: %[^\n]\n", newTheme.iconSet);
        fscanf(file, "Color Scheme: %[^\n]\n\n", newTheme.colorScheme);
        if (customThemeCount < MAX_CUSTOM_THEMES) {
            customThemes[customThemeCount++] = newTheme;
            printf("Loaded theme: %s\n", newTheme.name);
        } else {
            printf("Maximum custom themes reached. Skipping further themes in file.\n");
            break;
        }
    }
    fclose(file);
    printf("Themes loaded successfully from '%s'.\n", fileName);
}