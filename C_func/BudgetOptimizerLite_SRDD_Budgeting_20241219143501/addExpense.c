void addExpense(Budget *b, const char *category, double amount) {
    if (b->expenseCount >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(b->expenses[b->expenseCount].category, category);
    b->expenses[b->expenseCount].amount = amount;
    b->expenseCount++;
}