void GoalManager::removeGoal(const string& name) {
    vector<FinancialGoal>::iterator it;
    for (it = goals.begin(); it != goals.end(); ++it) {
        if (it->getName() == name) {
            goals.erase(it);
            cout << "Removed goal: " << name << endl;
            return;
        }
    }
    cout << "Goal not found: " << name << endl;
}