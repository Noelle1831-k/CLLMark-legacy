double SavingsGoal::getProgress() {
    double totalSavings = calculateTotalSavings();
    return (totalSavings / target) * 100;
}