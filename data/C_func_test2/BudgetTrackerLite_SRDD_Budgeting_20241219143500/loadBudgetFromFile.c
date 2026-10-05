void loadBudgetFromFile(Budget *budget, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to load budget from file.\n");
        return;
    }
    fscanf(file, "%f\n%f\n%f\n", &budget->totalIncome, &budget->totalExpenses, &budget->budgetGoal);
    fclose(file);
    printf("Budget loaded from file: %s\n", filename);
}