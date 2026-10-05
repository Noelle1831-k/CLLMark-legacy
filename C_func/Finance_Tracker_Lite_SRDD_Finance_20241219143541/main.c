int main() {
    int choice;
    while (1) {
        printf("\nFinance Tracker Lite\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Report\n");
        printf("4. Set Budget\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                viewReport();
                break;
            case 4:
                setBudget();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}