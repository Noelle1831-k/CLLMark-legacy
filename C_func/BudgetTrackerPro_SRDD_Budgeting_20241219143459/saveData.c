void saveData() {
    FILE *file = fopen("budget_data.txt", "w");
    if (file != NULL) {
        fprintf(file, "%lf\n", budgetGoal);  
        for (int i = 0; i < incomeIndex; i++) {
            fprintf(file, "%lf\n", incomeList[i]);  
        }
        for (int i = 0; i < expenseIndex; i++) {
            fprintf(file, "%lf\n", expenseList[i]);  
        }
        fclose(file);
        printf("Data saved successfully.\n");
    } else {
        printf("Error saving data.\n");
    }
}