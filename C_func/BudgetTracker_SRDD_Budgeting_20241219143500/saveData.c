void saveData() {
    FILE *file = fopen("budget_data.txt", "w");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    fprintf(file, "%f\n", totalIncome);
    fprintf(file, "%d\n", expenseCount);
    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%f %s\n", expenses[i].amount, expenses[i].category);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}