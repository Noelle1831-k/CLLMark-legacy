void loadFromFile() {
    FILE *file = fopen("expenses.dat", "rb");
    if (!file) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    fread(&expenseCount, sizeof(int), 1, file);
    fread(expenses, sizeof(Expense), expenseCount, file);
    fclose(file);
    printf("Data loaded successfully.\n");
}