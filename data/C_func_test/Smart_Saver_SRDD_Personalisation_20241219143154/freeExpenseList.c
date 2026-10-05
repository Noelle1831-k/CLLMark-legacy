void freeExpenseList(ExpenseList *list) {
    Expense *current = list->head;
    while (current) {
        Expense *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}