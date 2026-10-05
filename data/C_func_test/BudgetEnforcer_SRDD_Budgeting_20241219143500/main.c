int main() {
    printf("Welcome to BudgetEnforcer!\n");
    initializeUserData();
    int choice;
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Manage Budget\n");
        printf("2. View Progress\n");
        printf("3. Gamification Challenges\n");
        printf("4. Save and Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input. Please enter a number.");
        }
        switch (choice) {
            case 1:
                manageBudget();
                break;
            case 2:
                viewProgress();
                break;
            case 3:
                gamificationMenu();
                break;
            case 4:
                saveAllData();
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}