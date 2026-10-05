int main() {
    int choice;
    while (1) {
        printf("\n============================\n");
        printf("      Expense Monitor       \n");
        printf("============================\n");
        printf("1. Add Expense\n");
        printf("2. View Report\n");
        printf("3. Set Budget\n");
        printf("4. Check Budget\n");
        printf("5. Exit\n");
        printf("============================\n");
        printf("Enter your choice: ");
        choice = getIntInput();
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                generateReport();
                break;
            case 3:
                setBudget();
                break;
            case 4:
                checkBudget();
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}