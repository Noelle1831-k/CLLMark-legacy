void Recommendation::generateRecommendations(const User &user, BudgetAdvisor &budgetAdvisor) {
    budgetAdvisor.provideBudgetingTips(user);
    double savingsGoal = user.getSavingsGoal();
    double income = user.getIncome();
    if (savingsGoal > (income * 0.25)) {
        cout << "Recommendation: You may want to reassess your savings goal. Aim for a more manageable percentage of your income." << endl;
    } else {
        cout << "Great job! You're on track with your savings goal." << endl;
    }
}