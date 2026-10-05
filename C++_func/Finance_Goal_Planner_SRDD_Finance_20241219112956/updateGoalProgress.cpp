void GoalManager::updateGoalProgress(const string& name, double amount) {
    vector<FinancialGoal>::iterator it;
    for (it = goals.begin(); it != goals.end(); ++it) {
        if (it->getName() == name) {
            it->updateProgress(amount);
            if (it->checkMilestones()) {
                cout << "Milestone notification sent for " << name << endl;
            }
            return;
        }
    }
    cout << "Goal not found: " << name << endl;
}