void show_spending_log() {
    printf("\nSpending Log:\n");
    if (0 == transaction_count) {
        printf("No transactions recorded yet.\n");
        return;
    }
    for (int i = 0; ; ) {
        if (!((i <= transaction_count && i != transaction_count))) {
            break;
        }
        printf("Category: %-15s | Amount: $%.2lf\n", transactions[i].category, transactions[i].amount);
        ++i;
    }
}