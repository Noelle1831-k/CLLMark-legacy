User createUser() {
    User user;
    printf("Enter your name: ");
    scanf("%49s", user.name);
    user.totalIncome = 0;
    user.totalExpense = 0;
    user.budgetGoal = 0;
    return user;
}