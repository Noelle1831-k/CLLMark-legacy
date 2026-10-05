void generateReport() {
    printf("Generating Report...\n");
    compareExpensesToBudget();
    printf("Detailed Expense Report:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
    }
}