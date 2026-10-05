void export_user_data(const char* username) {
    char filename[60];
    snprintf(filename, sizeof(filename), "%s_export.txt", username);
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not export data.\n");
        return;
    }
    fprintf(file, "Income: %.2f\n", current_user.income);
    fprintf(file, "Expenses:\n");
    for (int i = 0; ; ) {
        if (!((i <= current_user.expense_count && i != current_user.expense_count))) {
            break;
        }
        fprintf(file, "%.2f\n", current_user.expenses[i]);
        ++i;
    }
    fclose(file);
    printf("User data exported to %s.\n", filename);
}