void Visualization::displayProgress(GoalTracker &tracker) {
    vector<FinancialGoal> goals = tracker.getGoals();
    for (FinancialGoal &goal : goals) {
        cout << "Goal: " << goal.getName() << " - Progress: " << goal.getProgress() << "%" << endl;
    }
}