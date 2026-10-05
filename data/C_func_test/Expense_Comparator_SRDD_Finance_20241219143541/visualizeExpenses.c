void visualizeExpenses(ExpenseList *list) {
    printf("\n=== Expense Visualization ===\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s: ", list->expenses[i].category);
        int bars = (int)(list->expenses[i].amount / 10);
        for (int j = 0; j < bars; j++) {
            printf("#");
        }
        printf(" (%.2f)\n", list->expenses[i].amount);
    }
}