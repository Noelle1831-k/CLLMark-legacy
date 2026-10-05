void loadIncomeData() {
    FILE *file = fopen("income_data.txt", "r");
    if (!file) {
        return; 
    }
    while (fscanf(file, " %49[^|]|%lf\n", incomeEntries[incomeCount].description, &incomeEntries[incomeCount].amount) == 2) {
        incomeCount++;
    }
    fclose(file);
}