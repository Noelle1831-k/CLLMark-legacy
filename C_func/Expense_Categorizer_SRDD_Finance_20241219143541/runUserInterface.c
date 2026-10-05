void runUserInterface() {
    ExpenseManager expenseManager;
    CategoryManager categoryManager;
    initializeExpenseManager(&expenseManager);
    initializeCategoryManager(&categoryManager);
    int choice;
    do {
        printf("1. Add Expense\n2. List Expenses\n3. Add Category\n4. List Categories\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                double amount;
                char date[20], category[50];
                printf("Enter amount: ");
                scanf("%lf", &amount);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter category: ");
                scanf("%s", category);
                Expense* expense = createExpense(amount, date, category);
                addExpense(&expenseManager, expense);
                break;
            }
            case 2:
                listExpenses(&expenseManager);
                break;
            case 3: {
                char name[50];
                printf("Enter category name: ");
                scanf("%s", name);
                Category* category = createCategory(name);
                addCategory(&categoryManager, category);
                break;
            }
            case 4:
                listCategories(&categoryManager);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    cleanupExpenseManager(&expenseManager);
    cleanupCategoryManager(&categoryManager);
}