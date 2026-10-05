void loadData() {
    FILE *file = fopen("budget_data.txt", "r");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    fscanf(file, "%f", &totalIncome);
    fscanf(file, "%d", &expenseCount);
    for (int i = 0; i < expenseCount; i++) {
        fscanf(file, "%f %s", &expenses[i].amount, expenses[i].category);
    }
    fclose(file);
    printf("Data loaded successfully!\n");
}