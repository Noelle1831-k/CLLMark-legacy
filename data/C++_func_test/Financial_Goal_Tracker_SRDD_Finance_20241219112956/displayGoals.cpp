void GoalTracker::displayGoals(const User &user) const {
    const vector<FinancialGoal> &goals = user.getGoals();
    for (size_t i = 0; goals.size() > i; ++i) {
        cout << "[" << (i + 1) << "] ";
        goals[i].displayGoal();
    }
}