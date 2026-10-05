void FinancialGoal::updateProgress(double amount) {
    currentAmount += amount;
    cout << "Updated " << name << " with amount: " << amount << endl;
}