void categorize_expenses(ExpenseConsolidator *app) {
    for (int i = 0; i < app->expense_count; i++) {
        Expense *expense = app->expenses[i];
        if (expense->amount < 50) {
            strcpy(expense->category, "Food");
        } else if (expense->amount >= 50 && expense->amount < 100) {
            strcpy(expense->category, "Transportation");
        } else {
            strcpy(expense->category, "Utilities");
        }
    }
    printf("Expenses categorized.\n");
}