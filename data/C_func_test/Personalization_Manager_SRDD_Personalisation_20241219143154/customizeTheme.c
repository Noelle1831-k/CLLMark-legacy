void customizeTheme() {
    if (customThemeCount >= MAX_CUSTOM_THEMES) {
        printf("Maximum custom themes reached. Cannot create more.\n");
        return;
    }
    Theme newTheme;
    printf("Enter a name for your custom theme: ");
    scanf(" %[^\n]", newTheme.name);
    printf("Enter wallpaper path: ");
    scanf(" %[^\n]", newTheme.wallpaper);
    printf("Enter screen saver path: ");
    scanf(" %[^\n]", newTheme.screenSaver);
    printf("Enter icon set: ");
    scanf(" %[^\n]", newTheme.iconSet);
    printf("Enter color scheme: ");
    scanf(" %[^\n]", newTheme.colorScheme);
    customThemes[customThemeCount++] = newTheme;
    printf("Custom theme '%s' created successfully!\n", newTheme.name);
}