void saveUserData() {
    FILE *file = fopen(DATA_FILE, "w");
    if (!file) {
        printf("Error saving data.\n");
        return;
    }
    fprintf(file, "%.2f %.2f %.2f %.2f\n", budget.income, budget.expenses, budget.savingsTarget, budget.currentSavings);
    fclose(file);
}