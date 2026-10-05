void SavingsTracker::trackSavings() {
    cout << "Enter amount saved: ";
    double saved;
    cin >> saved;
    if (saved < 0) {
        cout << "Saved amount cannot be negative. Please try again." << endl;
        return;
    }
    currentSavings += saved;
    cout << "Progress: $" << currentSavings << " / $" << savingsGoal << endl;
    if (currentSavings >= savingsGoal) {
        cout << "Congratulations! You have achieved your savings goal!" << endl;
    } else {
        cout << "Keep going! You're making progress." << endl;
    }
}