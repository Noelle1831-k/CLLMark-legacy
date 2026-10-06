void generate_report(User* user) {
    printf("\n=== Financial Report ===\n");
    printf("Total Income: %.2f\n", user->total_income);
    printf("Total Expenses: %.2f\n", user->total_expenses);
    printf("Balance: %.2f\n", user->balance);
    printf("\n=== Transaction History ===\n");
    print_transactions(user->transactions, user->transaction_count);
    track_budget(user);
}