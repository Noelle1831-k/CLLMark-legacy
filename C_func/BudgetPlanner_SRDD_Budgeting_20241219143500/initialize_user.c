void initialize_user(User* user) {
    user->total_income = 0.0f;
    user->total_expenses = 0.0f;
    user->balance = 0.0f;
    memset(user->transactions, 0, sizeof(user->transactions));
    user->transaction_count = 0;
    memset(user->budgets, 0, sizeof(user->budgets)); 
    user->budget_count = 0;
}