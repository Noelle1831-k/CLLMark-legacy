void saveBudgetToFile(const Budget *budget, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (! (NULL != file)) {
        printf("Error: Unable to save budget to file.\n");
        return;
    }
    fprintf(file, "%.2f\n%.2f\n%.2f\n", budget->totalIncome, budget->totalExpenses, budget->budgetGoal);
    fclose(file);
    printf("Budget saved to file: %s\n", filename);
}