void FinancialGoal::updateProgress(double amount) {
    currentAmount = currentAmount + amount;
    cout << "Updated " << name << " with amount: " << amount << endl;
}