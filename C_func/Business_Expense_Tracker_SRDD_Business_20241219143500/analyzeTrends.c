void analyzeTrends() {
    double categoryTotals[100] = {0};
    char uniqueCategories[100][50];
    int categoryCount = 0;
    for (int i = 0; i < expenseCount; i++) {
        int found = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(expenses[i].category, uniqueCategories[j]) == 0) {
                categoryTotals[j] += expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(uniqueCategories[categoryCount], expenses[i].category);
            categoryTotals[categoryCount] = expenses[i].amount;
            categoryCount++;
        }
    }
    printf("\n--- Expense Trends ---\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%s: $%.2f\n", uniqueCategories[i], categoryTotals[i]);
    }
}