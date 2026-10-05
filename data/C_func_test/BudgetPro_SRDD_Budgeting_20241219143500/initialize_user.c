void initialize_user(const char* username) {
    strcpy(current_user.username, username);
    current_user.income = 0.0f;
    current_user.expense_count = 0;
    printf("User profile initialized for %s.\n", username);
}