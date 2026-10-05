int load_user_data(const char* username) {
    char filename[60];
    snprintf(filename, sizeof(filename), "%s_data.txt", username);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0; 
    }
    fscanf(file, "%f", &current_user.income);
    fscanf(file, "%d", &current_user.expense_count);
    for (int i = 0; i < current_user.expense_count; i++) {
        fscanf(file, "%f", &current_user.expenses[i]);
    }
    fclose(file);
    strcpy(current_user.username, username);
    printf("User data loaded for %s.\n", username);
    return 1;
}