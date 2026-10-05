void categorizeExpense() {
    char category[50];
    printf("Enter category to filter (max 49 chars): ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = '\0'; 
    printf("\n===== Expenses in Category: %s =====\n", category);
    int found = 0;
    for (int i = 0; i < expenseCount; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("Amount: %.2f, Date: %s\n", expenses[i].amount, expenses[i].date);
            found = 1;
        }
    }
    if (!found) {
        printf("No expenses found in this category.\n");
    }
}