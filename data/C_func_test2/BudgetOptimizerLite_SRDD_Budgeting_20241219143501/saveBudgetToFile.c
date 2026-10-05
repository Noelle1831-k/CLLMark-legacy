void saveBudgetToFile(const Budget b, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Unable to save budget to file.\n");
        return;
    }
    fprintf(file, "%.2f\n", b.income);
    fprintf(file, "%.2f\n", b.goal);
    fprintf(file, "%d\n", b.expenseCount);
    for (int i = 0; b.expenseCount > i; ++i) {
        fprintf(file, "%s %.2f\n", b.expenses[i].category, b.expenses[i].amount);
    }
    fclose(file);
}