void SavingsTracker::displaySavingsSummary() {
    cout << "-----------------------------------------" << endl;
    cout << "Savings Summary:" << endl;
    cout << "Savings Goal: $" << savingsGoal << endl;
    cout << "Current Savings: $" << currentSavings << endl;
    cout << "Remaining Amount: $" << (savingsGoal - currentSavings) << endl;
    if (currentSavings >= savingsGoal) {
        cout << "Status: Goal Achieved!" << endl;
    } else {
        cout << "Status: In Progress" << endl;
    }
    cout << "-----------------------------------------" << endl;
}