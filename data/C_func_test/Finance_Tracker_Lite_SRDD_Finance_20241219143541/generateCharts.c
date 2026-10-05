void generateCharts() {
    printf("\nSpending Breakdown by Category (ASCII Chart):\n");
    double categoryTotals[MAX_TRANSACTIONS] = {0};
    char categories[MAX_TRANSACTIONS][50];
    int uniqueCategories = 0;
    for (int i = 0; i < transactionCount; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCategories; j++) {
            if (strcmp(categories[j], transactions[i].category) == 0) {
                categoryTotals[j] += transactions[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[uniqueCategories], transactions[i].category);
            categoryTotals[uniqueCategories] = transactions[i].amount;
            uniqueCategories++;
        }
    }
    for (int i = 0; i < uniqueCategories; i++) {
        printf("%s: ", categories[i]);
        int bars = (int)(categoryTotals[i] / 10); 
        for (int j = 0; j < bars; j++) {
            printf("|");
        }
        printf(" %.2lf\n", categoryTotals[i]);
    }
}