void loadData() {
    FILE *file = fopen("budget_data.txt", "r");
    if (file != NULL) {
        fscanf(file, "%lf", &budgetGoal);  
        while (fscanf(file, "%lf", &incomeList[incomeIndex]) != EOF) {
            incomeIndex++;  
        }
        while (fscanf(file, "%lf", &expenseList[expenseIndex]) != EOF) {
            expenseIndex++;  
        }
        fclose(file);
        printf("Data loaded successfully.\n");
    } else {
        printf("No previous data found, starting fresh.\n");
    }
}