void displayExpenses(ExpenseList *list) {
    Expense *current = list->head;
    if (!current) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("Expenses:\n");
    while (current) {
        printf("Category: %s, Amount: $%.2f, Date: %s\n", current->category, current->amount, current->date);
        current = current->next;
    }
}