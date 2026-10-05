int main() {
    int choice;
    double amount;
    char description[100];
    while (1) {
        clearScreen();
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); 
        switch (choice) {
            case 1:
                printf("Enter income amount: ");
                scanf("%lf", &amount);
                clearInputBuffer(); 
                printf("Enter description: ");
                fgets(description, sizeof(description), stdin);
                sanitizeInput(description);
                addIncome(amount, description);
                break;
            case 2:
                printf("Enter expense amount: ");
                scanf("%lf", &amount);
                clearInputBuffer(); 
                printf("Enter description: ");
                fgets(description, sizeof(description), stdin);
                sanitizeInput(description);
                addExpense(amount, description);
                break;
            case 3:
                printf("Enter budget goal amount: ");
                scanf("%lf", &amount);
                clearInputBuffer(); 
                setBudgetGoal(amount);
                break;
            case 4:
                viewBudgetBreakdown();
                pause();
                break;
            case 5:
                trackSavings();
                pause();
                break;
            case 6:
                printf("Exiting application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                pause();
        }
    }
    return 0;
}