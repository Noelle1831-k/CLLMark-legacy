int main() {
    int choice;
    initializeGoalManager();
    initializeReminders();
    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                createGoal();
                break;
            case 2:
                assignGoal();
                break;
            case 3:
                trackProgress();
                break;
            case 4:
                displayVisualizations();
                break;
            case 5:
                setReminder();
                break;
            case 6:
                celebrateAchievements();
                break;
            case 7:
                viewAllGoals();
                break;
            case 8:
                printf("Exiting Family Goal Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}