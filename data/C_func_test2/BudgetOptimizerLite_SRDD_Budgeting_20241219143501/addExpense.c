void addExpense(Budget *b, const char *category, double amount) {
    if ((MAX_EXPENSES < b->expenseCount || MAX_EXPENSES == b->expenseCount)) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(b->expenses[b->expenseCount].category, category);
    b->expenses[b->expenseCount].amount = amount;
    b->expenseCount++;
}