void addExpense(ExpenseList *list) {
    if (list->capacity == list->count) {
        list->capacity = list->capacity * 2;
        list->expenses = (Expense *)realloc(list->expenses, list->capacity * sizeof(Expense));
    }
    Expense newExpense;
    printf("Enter category (e.g., groceries, transportation): ");
    fgets(newExpense.category, sizeof(newExpense.category), stdin);
    strtok(newExpense.category, "\n"); 
    printf("Enter amount: ");
    scanf("%lf", &newExpense.amount);
    getchar(); 
    printf("Enter date (YYYY-MM-DD): ");
    fgets(newExpense.date, sizeof(newExpense.date), stdin);
    strtok(newExpense.date, "\n"); 
    list->expenses[list->count++] = newExpense;
    printf("Expense added successfully!\n");
}