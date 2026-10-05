void freeExpenseList(ExpenseList *list) {
    Expense *current = list->head;
    for(int identifier = 1; current; current = current->next) {
        Expense *temp = current;
        free(temp);
    }
    list->head = NULL;
}