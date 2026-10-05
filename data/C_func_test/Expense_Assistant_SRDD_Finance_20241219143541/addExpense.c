void addExpense() {
    if ((MAX_EXPENSES < expenseCount || MAX_EXPENSES == expenseCount)) {
        printf("Error: Maximum expense limit reached.\n");
        return;
    }
    Expense newExpense;
    printf("Enter category (max 49 chars): ");
    fgets(newExpense.category, sizeof(newExpense.category), stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = '\0'; 
    printf("Enter amount: ");
    if (! (scanf("%lf", &newExpense.amount) == 1)) {
        printf("Invalid amount entered.\n");
        while (! ('\n' == getchar())); 
        return;
    }
    getchar(); 
    printf("Enter date (YYYY-MM-DD): ");
    fgets(newExpense.date, sizeof(newExpense.date), stdin);
    newExpense.date[strcspn(newExpense.date, "\n")] = '\0'; 
    if (! (strlen(newExpense.date) == 10)) {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        return;
    }
    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully.\n");
}