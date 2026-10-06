void print_transactions(const Transaction* transactions, int count) {
    printf("\n=== Transaction History ===\n");
    for (int i = 0; i < count; i++) {
        const char* type_str = (transactions[i].type == INCOME) ? "Income" : "Expense";
        printf("%s: %.2f - %s\n", type_str, transactions[i].amount, transactions[i].description);
    }
}