double FinancialGoal::getProgress() {
    return (currentAmount / targetAmount) * 100;
}