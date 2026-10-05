void saveExpenseData() {
    FILE *file = fopen("expense_data.txt", "w");
    if (!file) {
        printf("Error saving expense data.\n");
        return;
    }
    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%s|%lf\n", expenseEntries[i].description, expenseEntries[i].amount);
    }
    fclose(file);
}