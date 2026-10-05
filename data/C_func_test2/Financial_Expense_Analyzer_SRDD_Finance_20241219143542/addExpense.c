void addExpense() {
    if (expenseCount < MAX_EXPENSES) {
        printf("Enter category: ");
        if (!fgets(expenses[expenseCount].category, MAX_CATEGORY_LENGTH, stdin)) {
            printf("Error reading category.\n");
            return;
        }
        stripNewline(expenses[expenseCount].category);
        printf("Enter amount: ");
        if (scanf("%lf", &expenses[expenseCount].amount) != 1) {
            printf("Invalid amount. Please enter a valid number.\n");
            clearInputBuffer();
            return;
        }
        expenseCount++;
        printf("Expense added successfully.\n");
    } else {
        printf("Expense list is full.\n");
    }
}