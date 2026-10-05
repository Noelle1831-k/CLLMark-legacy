void FinancialGoal::updateProgress(double amount) {
    currentAmount = currentAmount + amount;
    cout << "Progress updated. Current amount: " << currentAmount << "\n";
}