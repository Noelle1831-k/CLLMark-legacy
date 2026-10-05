void runApp() {
    int choice;
    do {
        printf("\nBudgetPlannerLite Menu:\n");
        printf("1. Add Income\n");
        printf("2. List Income\n");
        printf("3. Add Expense\n");
        printf("4. List Expenses\n");
        printf("5. Set Budget Goal\n");
        printf("6. Check Goals\n");
        printf("7. Display Budget Breakdown\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                addIncome();
                break;
            case 2:
                listIncome();
                break;
            case 3:
                addExpense();
                break;
            case 4:
                listExpenses();
                break;
            case 5:
                setGoal();
                break;
            case 6:
                checkGoals();
                break;
            case 7:
                displayBudgetBreakdown();
                break;
            case 8:
                printf("Exiting BudgetPlannerLite...\n");
                saveIncomeData();
                saveExpenseData();
                saveGoalData();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
}