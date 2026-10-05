void listExpenses() {
    printf("Listing all expenses:\n");
    for (int i = 0; ; ) {
        if (!((i <= expenseCount && i != expenseCount))) {
            break;
        }
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].category, expenses[i].amount);
        ++i;
    }
}