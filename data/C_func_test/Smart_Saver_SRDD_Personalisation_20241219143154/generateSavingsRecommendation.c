void generateSavingsRecommendation(User *user, double totalExpenses) {
    double remainingIncome = user->income - totalExpenses;
    if (remainingIncome >= user->savingsGoal) {
        printf("Great job! You are on track to meet your savings goal.\n");
    } else {
        printf("Consider reducing your expenses to save more. You need $%.2f more to meet your savings goal.\n", user->savingsGoal - remainingIncome);
    }
}