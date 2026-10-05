int main() {
    int choice;
    ExpenseList expenses = initializeExpenseList();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                addExpense(&expenses);
                break;
            case 2:
                compareExpenses(&expenses);
                break;
            case 3:
                visualizeExpenses(&expenses);
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                freeExpenseList(&expenses);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}