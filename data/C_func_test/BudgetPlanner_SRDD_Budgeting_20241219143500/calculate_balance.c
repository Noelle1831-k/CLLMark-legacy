void calculate_balance(User* user) {
    user->balance = user->total_income - user->total_expenses;
    printf("Current Balance: %.2f\n", user->balance);
}