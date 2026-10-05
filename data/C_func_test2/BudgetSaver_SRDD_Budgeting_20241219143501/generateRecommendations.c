void generateRecommendations() {
    printf("\n=== Recommendations ===\n");
    printf("1. Reduce spending on non-essential categories.\n");
    printf("2. Set a monthly budget for each category.\n");
    printf("3. Track your expenses regularly.\n");
    printf("4. Avoid impulse purchases.\n");
    printf("5. Consider switching to cheaper alternatives for recurring expenses.\n");
    double total = 0;
    double categoryTotals[MAX_EXPENSES] = {0};
    char categories[MAX_EXPENSES][50];
    int categoryCount = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
        int found = 0;
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(categories[j], expenses[i].category) == 0) {
                categoryTotals[j] += expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[categoryCount], expenses[i].category);
            categoryTotals[categoryCount] = expenses[i].amount;
            categoryCount++;
        }
    }
    for (int i = 0; i < categoryCount; i++) {
        printf("Category %s: %.2f%% of total expenses\n", categories[i], (categoryTotals[i] / total) * 100);
    }
}