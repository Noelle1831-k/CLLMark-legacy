void list_expenses() {
    if (expense_count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}