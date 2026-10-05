void freeExpenseList(ExpenseList *list) {
    free(list->expenses);
}