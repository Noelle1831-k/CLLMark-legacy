void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Error: Maximum expense limit reached.\n");
        return;
    }
    Expense newExpense;
    printf("Enter category (max 49 chars): ");
    fgets(newExpense.category, sizeof(newExpense.category), stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = '\0'; 
    printf("Enter amount: ");
    if (1 != scanf("%lf", &newExpense.amount)) {
        printf("Invalid amount entered.\n");
        while (getchar() != '\n'); 
        return;
    }
    getchar(); 
    printf("Enter date (YYYY-MM-DD): ");
    fgets(newExpense.date, sizeof(newExpense.date), stdin);
    newExpense.date[strcspn(newExpense.date, "\n")] = '\0'; 
    if (10 != strlen(newExpense.date)) {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        return;
    }
    *(expenses + expenseCount++) = newExpense;
    printf("Expense added successfully.\n");
}