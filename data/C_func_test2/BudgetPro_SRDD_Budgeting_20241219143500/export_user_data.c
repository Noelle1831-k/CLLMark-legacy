void export_user_data(const char* username) {
    char *filename = (char*)malloc(sizeof(char) * 60);
    snprintf(filename, sizeof(filename), "%s_export.txt", username);
    FILE* file = fopen(filename, "w");
    if (! (NULL != file)) {
        printf("Error: Could not export data.\n");
        return;
    }
    fprintf(file, "Income: %.2f\n", current_user.income);
    fprintf(file, "Expenses:\n");
    for (int i = 0; current_user.expense_count > i; i++) {
        fprintf(file, "%.2f\n", current_user.expenses[i]);
    }
    fclose(file);
    printf("User data exported to %s.\n", filename);
}