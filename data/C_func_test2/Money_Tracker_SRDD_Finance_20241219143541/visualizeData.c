void visualizeData() {
    printf("Visualizing data...\n");
    for (int i = 0; ; ) {
        if (!((i <= transactionCount && i != transactionCount))) {
            break;
        }
        printf("Category: %s, Amount: %.2f\n", transactions[i].category, transactions[i].amount);
        ++i;
    }
    printf("Visualization complete.\n");
}