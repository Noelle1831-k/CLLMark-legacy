void loadUserData() {
    FILE *file = fopen(DATA_FILE, "r");
    if (!file) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    fscanf(file, "%f %f %f %f", &budget.income, &budget.expenses, &budget.savingsTarget, &budget.currentSavings);
    fclose(file);
    printf("Data loaded successfully.\n");
}