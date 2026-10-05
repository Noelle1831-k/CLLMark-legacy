void resetUser(User *user) {
    strcpy(user->name, "DefaultUser");
    user->totalIncome = 0.0f;
    user->totalExpense = 0.0f;
    user->budgetGoal = 0.0f;
}