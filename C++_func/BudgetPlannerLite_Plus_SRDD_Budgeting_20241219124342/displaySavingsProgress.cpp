void SavingsTracker::displaySavingsProgress() {
    cout << "Savings Goal: $" << fixed << setprecision(2) << savingsGoal << endl;
    cout << "Current Savings: $" << fixed << setprecision(2) << currentSavings << endl;
    if (savingsGoal > 0) {
        cout << "Progress: " << fixed << setprecision(2) << (currentSavings / savingsGoal) * 100 << "%" << endl;
    } else {
        cout << "Progress: 0% (No goal set)" << endl;
    }
}