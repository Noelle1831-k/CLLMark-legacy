void listIncome() {
    if (incomeCount == 0) {
        printf("No income entries found.\n");
        return;
    }
    printf("\nIncome Entries:\n");
    for (int i = 0; i < incomeCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, incomeEntries[i].description, incomeEntries[i].amount);
    }
}