void BudgetManager::setBudgetGoal(double goal) {
    if (goal > 0) {
        budgetGoal = goal;
        cout << "Budget goal set successfully!\n";
    } else {
        cout << "Invalid budget goal.\n";
    }
}