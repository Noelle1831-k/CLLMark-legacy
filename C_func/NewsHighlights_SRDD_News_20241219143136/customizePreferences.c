void customizePreferences() {
    printf("\n--- Customize Preferences ---\n");
    printf("Available Categories: Finance, Sports, Technology\n");
    printf("Enter your preferred categories (comma-separated): ");
    char preferences[256];
    scanf(" %[^\n]s", preferences);
    savePreferences(preferences);
}