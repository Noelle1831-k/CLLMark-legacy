void analyzeTransactions(struct Transaction* transactions, int count) {
    double totalIncome = 0;
    double totalExpense = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(transactions[i].type, "income") == 0) {
            totalIncome += transactions[i].amount;
        } else if (strcmp(transactions[i].type, "expense") == 0) {
            totalExpense += transactions[i].amount;
        }
    }
    printf("========== Analysis ==========\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", totalIncome - totalExpense);
    printf("==============================\n");
}