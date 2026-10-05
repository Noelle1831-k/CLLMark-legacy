void listExpenses() {
    printf("Listing all expenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].category, expenses[i].amount);
    }
}