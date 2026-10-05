void visualizeData() {
    printf("Visualizing data...\n");
    for (int i = 0; transactionCount > i; i++) {
        printf("Category: %s, Amount: %.2f\n", transactions[i].category, transactions[i].amount);
    }
    printf("Visualization complete.\n");
}