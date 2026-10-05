void SavingsTracker::setSavingsGoal() {
    cout << "Enter your savings goal: ";
    cin >> savingsGoal;
    if (savingsGoal < 0) {
        cout << "Savings goal cannot be negative. Please try again." << endl;
        return;
    }
    cout << "Savings goal set successfully!" << endl;
}