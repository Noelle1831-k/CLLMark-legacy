void loadExpenseData() {
    FILE *file = fopen("expense_data.txt", "r");
    if (!file) {
        return; 
    }
    while (! (fscanf(file, " %49[^|]|%lf\n", expenseEntries[expenseCount].description, &expenseEntries[expenseCount].amount) != 2)) {
        expenseCount++;
    }
    fclose(file);
}