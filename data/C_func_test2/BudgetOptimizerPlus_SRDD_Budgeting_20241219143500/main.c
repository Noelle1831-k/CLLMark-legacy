int main() {
    initializeUI();
    logMessage("UI initialized successfully.");
    int choice;
    while (1) {
        choice = getUserChoice();
        if (choice == 0) {
            logMessage("Exiting the application...");
            break;
        }
        switch (choice) {
            case 1:
                manageBudget();
                break;
            case 2:
                trackSavings();
                break;
            case 3:
                provideRecommendations();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                logMessage("User entered an invalid choice.");
                break;
        }
    }
    cleanupUI();
    logMessage("UI cleaned up.");
    return 0;
}