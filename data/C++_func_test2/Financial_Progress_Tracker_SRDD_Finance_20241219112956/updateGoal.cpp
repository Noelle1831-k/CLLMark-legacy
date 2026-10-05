void GoalTracker::updateGoal(string name, double amount) {
    for (FinancialGoal &goal : goals) {
        if (goal.getName() == name) {
            goal.updateProgress(amount);
            goal.checkMilestone();
            return;
        }
    }
    cout << "Goal not found: " << name << endl;
}