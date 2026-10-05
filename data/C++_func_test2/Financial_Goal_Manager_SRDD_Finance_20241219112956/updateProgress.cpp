void FinancialGoal::updateProgress(double amount) {
    currentAmount += amount;
    cout << "Progress updated. Current amount: " << currentAmount << "\n";
}