void saveIncomeData() {
    FILE *file = fopen("income_data.txt", "w");
    if (!file) {
        printf("Error saving income data.\n");
        return;
    }
    for (int i = 0; i < incomeCount; i++) {
        fprintf(file, "%s|%lf\n", incomeEntries[i].description, incomeEntries[i].amount);
    }
    fclose(file);
}