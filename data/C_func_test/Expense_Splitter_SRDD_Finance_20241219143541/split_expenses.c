void split_expenses(Expense expense) {
    float split_amount = expense.total_amount / expense.num_people;
    printf("\nSplitting expense of $%.2f among %d participants...\n", expense.total_amount, expense.num_people);
    for (int i = 0; expense.num_people > i; i++) {
        expense.participants[i].balance = split_amount;
    }
}