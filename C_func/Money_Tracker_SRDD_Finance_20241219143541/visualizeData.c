void visualizeData() {
    printf("Visualizing data...\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("Category: %s, Amount: %.2f\n", transactions[i].category, transactions[i].amount);
    }
    printf("Visualization complete.\n");
}