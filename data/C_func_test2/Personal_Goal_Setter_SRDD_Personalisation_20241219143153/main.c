int main() {
    int userChoice;
    Goal userGoals[MAX_GOALS];
    Progress userProgress[MAX_GOALS];
    int goalCount = 0;
    initializeGoals(userGoals);
    initializeProgress(userProgress);
    printf("Welcome to the Personal Goal Tracker!\n");
    while (1) {
        printf("\n1. Set a New Goal\n2. View Progress\n3. Update Progress\n4. Get Recommendations\n5. Set Reminder\n6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1:
                setGoal(userGoals, &goalCount);
                break;
            case 2:
                viewProgress(userGoals, userProgress, goalCount);
                break;
            case 3:
                updateProgress(userGoals, userProgress, goalCount);
                break;
            case 4:
                getRecommendations(userGoals, goalCount);
                break;
            case 5:
                setReminder(userGoals, goalCount);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}