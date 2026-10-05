int main() {
    printf("Welcome to the Financial Goal Tracker!\n");
    Goal goals[MAX_GOALS];
    int goalCount = 0;
    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Add Goal\n");
        printf("2. View Goals\n");
        printf("3. Update Progress\n");
        printf("4. View Progress\n");
        printf("5. Set Milestones\n");
        printf("6. Check Notifications\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); 
        switch (choice) {
            case 1:
                addGoal(goals, &goalCount);
                break;
            case 2:
                viewGoals(goals, goalCount);
                break;
            case 3:
                updateProgress(goals, goalCount);
                break;
            case 4:
                viewProgress(goals, goalCount);
                break;
            case 5:
                setMilestones(goals, goalCount);
                break;
            case 6:
                checkMilestones(goals, goalCount);
                break;
            case 7:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}