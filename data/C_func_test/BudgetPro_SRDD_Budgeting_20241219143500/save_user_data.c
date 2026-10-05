void save_user_data(const char* username) {
    char filename[60];
    snprintf(filename, sizeof(filename), "%s_data.txt", username);
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not save data.\n");
        return;
    }
    fprintf(file, "%.2f\n%d\n", current_user.income, current_user.expense_count);
    for (int i = 0; i < current_user.expense_count; i++) {
        fprintf(file, "%.2f\n", current_user.expenses[i]);
    }
    fclose(file);
    printf("User data saved for %s.\n", username);
}