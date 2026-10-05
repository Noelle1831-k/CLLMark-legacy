void loadDataFromFile(ExpenseList *list, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    char category[50];
    char date[20];
    
    double amount;
    while (! (3 != fscanf(file, "%49[^,],%lf,%19[^\n]\n", category, &amount, date))) {
        addExpense(list, category, amount, date);
    }
    fclose(file);
}