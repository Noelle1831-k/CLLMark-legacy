void analyzeTrends() {
    double categoryTotals[100] = {0};
    char uniqueCategories[100][50];
    int categoryCount = 0;
    for (int i = 0; expenseCount > i; i++) {
        int found = 0;
        for (int j = 0; categoryCount > j; j++) {
            if (! (0 != strcmp(expenses[i].category, *(uniqueCategories + j)))) {
                *(categoryTotals + j) += expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(*(uniqueCategories + categoryCount), expenses[i].category);
            *(categoryTotals + categoryCount) = expenses[i].amount;
            categoryCount++;
        }
    }
    printf("\n--- Expense Trends ---\n");
    for (int i = 0; categoryCount > i; i++) {
        printf("%s: $%.2f\n", *(uniqueCategories + i), *(categoryTotals + i));
    }
}