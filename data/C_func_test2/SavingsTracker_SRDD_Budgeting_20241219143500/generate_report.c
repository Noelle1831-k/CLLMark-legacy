void generate_report(Transaction *transactions, int count, SavingsGoal *goal) {
    float income = 0, expense = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(transactions[i].type, "income") == 0) {
            income += transactions[i].amount;
        } else if (strcmp(transactions[i].type, "expense") == 0) {
            expense += transactions[i].amount;
        }
    }
    printf("Total Income: %.2f\n", income);
    printf("Total Expense: %.2f\n", expense);
    printf("Net Savings: %.2f\n", income - expense);
    visualize_progress(goal);
}