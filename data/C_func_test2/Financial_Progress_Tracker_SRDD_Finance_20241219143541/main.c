int main() {
    initializeApplication();
    while (1) {
        int choice = displayMainMenu();
        switch (choice) {
            case 1:
                handleSetGoal();
                break;
            case 2:
                handleViewProgress();
                break;
            case 3:
                handleSetMilestone();
                break;
            case 4:
                handleNotifications();
                break;
            case 5:
                displayTimeline();
                break;
            case 6:
                exitApplication();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}