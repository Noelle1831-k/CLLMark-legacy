int main(void) {
    printf("Welcome to SleepWell!\n");
    initializeSleepTracker();
    initializeReminders();
    initializeRelaxationTechniques();
    initializeGoals();
    initializeRecommendations();
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                trackSleep();
                break;
            case 2:
                setReminder();
                break;
            case 3:
                showRelaxationTechniques();
                break;
            case 4:
                setSleepGoals();
                break;
            case 5:
                provideRecommendations();
                break;
            case 6:
                viewSleepStatistics();
                break;
            case 7:
                printf("Exiting SleepWell. Good night!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}