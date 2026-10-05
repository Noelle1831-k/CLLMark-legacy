void handleUserInput() {
    int choice;
    double income = 0;
    double savingsGoal = 0;
    double expenses[5] = {0};
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            clearInputBuffer();
            pause();
            clearScreen();
            continue;
        }
        switch (choice) {
            case 1:
                income = getUserIncome();
                break;
            case 2:
                savingsGoal = getUserSavingsGoal();
                break;
            case 3:
                getUserExpenses(expenses);
                break;
            case 4:
                calculateSavings(income, savingsGoal, expenses);
                break;
            case 5:
                allocateIncome(income, expenses);
                break;
            case 6:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        pause();
        clearScreen();
    }
}