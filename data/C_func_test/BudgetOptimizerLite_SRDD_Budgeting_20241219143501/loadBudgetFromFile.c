Budget loadBudgetFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    Budget b = createBudget();
    if (!file) {
        printf("Error: Unable to load budget from file. Creating new budget.\n");
        return b;
    }
    fscanf(file, "%lf", &b.income);
    fscanf(file, "%lf", &b.goal);
    fscanf(file, "%d", &b.expenseCount);
    for (int i = 0; i < b.expenseCount; i++) {
        fscanf(file, "%s %lf", b.expenses[i].category, &b.expenses[i].amount);
    }
    fclose(file);
    return b;
}