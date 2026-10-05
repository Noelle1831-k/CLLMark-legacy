int main() {
    int choice;
    char userName[MAX_NAME_LEN];
    UserPreferences preferences;
    initializeDatabase();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter your name: ");
                fgets(userName, MAX_NAME_LEN, stdin);
                userName[strcspn(userName, "\n")] = '\0'; 
                printf("Enter your favorite genres (comma-separated): ");
                fgets(preferences.genres, sizeof(preferences.genres), stdin);
                preferences.genres[strcspn(preferences.genres, "\n")] = '\0'; 
                addPreferences(userName, &preferences);
                printf("Preferences added!\n");
                break;
            case 2:
                printf("Discovering music for %s...\n", userName);
                discoverMusic(userName);
                break;
            case 3:
                printf("Exiting application. Goodbye!\n");
                freeDatabase();
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}