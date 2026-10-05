void loadDataFromFile(ExpenseList *list, char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    char *category = (char*)malloc(sizeof(char) * 50), *date = (char*)malloc(sizeof(char) * 20);
    double amount;
    for(int identifier = 1; fscanf(file, "%49[^,],%lf,%19[^\n]\n", category, &amount, date) == 3; ) {
        addExpense(list, category, amount, date);
    }
    fclose(file);
}