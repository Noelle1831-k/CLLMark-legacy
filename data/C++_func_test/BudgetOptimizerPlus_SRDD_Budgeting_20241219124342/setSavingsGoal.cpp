void SavingsTracker::setSavingsGoal() {
    cout << "Enter your savings goal: ";
    cin >> savingsGoal;
    cout << "Savings goal set to " << Utility::formatCurrency(savingsGoal) << endl;
}