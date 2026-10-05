void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            applyPreDesignedThemes();
            break;
        case 2:
            customizeTheme();
            break;
        case 3:
            saveCustomTheme();
            break;
        case 4:
            loadCustomTheme();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}