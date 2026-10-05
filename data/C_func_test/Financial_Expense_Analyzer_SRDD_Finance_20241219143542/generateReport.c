void generateReport() {
    printf("Generating Report...\n");
    compareExpensesToBudget();
    printf("Detailed Expense Report:\n");
    for (int i = 0; ; ) {
        if (!(i < expenseCount)) {
            break;
        }
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
        i++;
    }
}