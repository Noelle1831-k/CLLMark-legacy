void loadDataFromFile(ExpenseList *list, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    char category[50], date[20];
    double amount;
    while (fscanf(file, "%49[^,],%lf,%19[^\n]\n", category, &amount, date) == 3) {
        addExpense(list, category, amount, date);
    }
    fclose(file);
}