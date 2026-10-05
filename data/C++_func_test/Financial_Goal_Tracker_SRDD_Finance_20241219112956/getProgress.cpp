double FinancialGoal::getProgress() const {
    return (currentAmount / targetAmount) * 100;
}