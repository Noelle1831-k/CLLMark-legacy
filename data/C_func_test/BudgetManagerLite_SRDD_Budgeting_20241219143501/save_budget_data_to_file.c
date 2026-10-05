void save_budget_data_to_file(float income, Expense expenses[], int expense_count) {
    FILE *file = fopen(DATA_FILE, "w");
    if (!file) {
        printf("Error: Unable to save data.\n");
        return;
    }
    fprintf(file, "%.2f\n", income);
    fprintf(file, "%d\n", expense_count);
    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s %.2f\n", expenses[i].name, expenses[i].amount);
    }
    fclose(file);
    printf("Data saved successfully.\n");
}