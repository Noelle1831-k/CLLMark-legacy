double getUserSavingsGoal() {
    double savingsGoal;
    getValidDouble("Enter your target savings: ", &savingsGoal);
    return savingsGoal;
}