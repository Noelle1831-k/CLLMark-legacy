void filterExpensesByCategory() {
    char category[50];
    printf("Enter category to filter: ");
    scanf(" %[^\n]", category);
    printf("\n--- Filtered Expenses ---\n");
    for (int i = 0; i < expenseCount; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("%d. %s | $%.2f | %s\n", i + 1, expenses[i].description, expenses[i].amount, expenses[i].date);
        }
    }
}