double calculateTotalExpenses(ExpenseList *list) {
    double total = 0.0;
    Expense *current = list->head;
    while (current) {
        total += current->amount;
        current = current->next;
    }
    return total;
}