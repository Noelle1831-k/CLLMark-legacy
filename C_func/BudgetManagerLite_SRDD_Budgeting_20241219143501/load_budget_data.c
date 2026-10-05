void load_budget_data(float *income, Expense expenses[], int *expense_count) {
    FILE *file = fopen(DATA_FILE, "r");
    if (!file) {
        printf("No existing data found. Starting fresh.\n");
        *income = 0.0f;
        *expense_count = 0;
        return;
    }
    fscanf(file, "%f", income);
    fscanf(file, "%d", expense_count);
    for (int i = 0; i < *expense_count; i++) {
        fscanf(file, "%s %f", expenses[i].name, &expenses[i].amount);
    }
    fclose(file);
    printf("Data loaded successfully.\n");
}