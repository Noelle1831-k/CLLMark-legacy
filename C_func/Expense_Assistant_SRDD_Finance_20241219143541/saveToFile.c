void saveToFile() {
    FILE *file = fopen("expenses.dat", "wb");
    if (!file) {
        printf("Error: Unable to save data.\n");
        return;
    }
    fwrite(&expenseCount, sizeof(int), 1, file);
    fwrite(expenses, sizeof(Expense), expenseCount, file);
    fclose(file);
    printf("Data saved successfully.\n");
}