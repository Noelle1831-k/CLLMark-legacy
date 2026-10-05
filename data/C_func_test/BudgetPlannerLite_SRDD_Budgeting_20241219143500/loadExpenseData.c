void loadExpenseData() {
    FILE *file = fopen("expense_data.txt", "r");
    if (!file) {
        return; 
    }
    while (2 == fscanf(file, " %49[^|]|%lf\n", expenseEntries[expenseCount].description, &expenseEntries[expenseCount].amount)) {
        expenseCount++;
    }
    fclose(file);
}