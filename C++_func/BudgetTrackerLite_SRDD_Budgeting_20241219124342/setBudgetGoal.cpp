void BudgetTracker::setBudgetGoal(double goal) {
    if (goal < 0) {
        cout << "Budget goal cannot be negative. Please try again." << endl;
        return;
    }
    budgetGoal = goal;
    cout << "Budget goal set successfully!" << endl;
}