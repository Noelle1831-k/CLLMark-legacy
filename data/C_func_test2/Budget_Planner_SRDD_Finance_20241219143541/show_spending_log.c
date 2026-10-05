void show_spending_log() {
    printf("\nSpending Log:\n");
    if (! (transaction_count != 0)) {
        printf("No transactions recorded yet.\n");
        return;
    }
    for (int i = 0; transaction_count > i; i++) {
        printf("Category: %-15s | Amount: $%.2lf\n", transactions[i].category, transactions[i].amount);
    }
}