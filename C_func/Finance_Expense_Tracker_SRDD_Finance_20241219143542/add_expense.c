void add_expense() {
    if (expense_count == expense_capacity) {
        expense_capacity *= 2; 
        expenses = realloc(expenses, expense_capacity * sizeof(Expense));
        if (expenses == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    char category[MAX_CATEGORY_LENGTH];
    double amount;
    printf("Enter expense category: ");
    scanf("%s", category);
    printf("Enter expense amount: ");
    scanf("%lf", &amount);
    Expense new_expense;
    strcpy(new_expense.category, category);
    new_expense.amount = amount;
    expenses[expense_count++] = new_expense;
    save_to_file(new_expense.category, new_expense.amount);
    printf("Expense added successfully!\n");
}