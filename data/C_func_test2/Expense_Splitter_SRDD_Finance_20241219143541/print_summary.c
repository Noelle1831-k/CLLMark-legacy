void print_summary(Expense expense) {
    printf("\nExpense Summary:\n");
    for (int i = 0; i < expense.num_people; i++) {
        printf("%s: $%.2f\n", expense.participants[i].name, expense.participants[i].balance);
    }
    printf("\nAll participants now have their shares of the expense. Please settle accordingly.\n");
}