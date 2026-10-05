void addExpense(ExpenseList *list, char *category, double amount, char *date) {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));
    strcpy(newExpense->category, category);
    newExpense->amount = amount;
    strcpy(newExpense->date, date);
    newExpense->next = list->head;
    list->head = newExpense;
}