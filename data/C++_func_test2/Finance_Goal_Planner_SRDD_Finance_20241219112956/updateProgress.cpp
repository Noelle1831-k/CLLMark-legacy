void FinancialGoal::updateProgress(double amount) {
    currentAmount += amount;
    cout << "Updated progress for " << name << ": " << currentAmount << "/" << targetAmount << endl;
}