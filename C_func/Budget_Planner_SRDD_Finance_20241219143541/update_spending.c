void update_spending() {
    if (transaction_count >= MAX_TRANSACTIONS) {
        printf("Transaction log is full!\n");
        return;
    }
    printf("\nEnter transaction category (e.g., Food, Rent, Entertainment): ");
    scanf("%s", transactions[transaction_count].category);
    printf("Enter transaction amount: ");
    transactions[transaction_count].amount = validate_input();
    transaction_count++;
    printf("Transaction added successfully!\n");
}