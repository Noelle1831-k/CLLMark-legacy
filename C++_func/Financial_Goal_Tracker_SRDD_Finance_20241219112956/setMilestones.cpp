void GoalTracker::setMilestones(User &user) {
    vector<FinancialGoal> &goals = user.getGoals();
    if (goals.empty()) {
        cout << "No goals available to set milestones!" << endl;
        return;
    }
    int index;
    double milestone;
    cout << "Select goal to set milestone (index): ";
    cin >> index;
    if (index < 1 || index > goals.size()) {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "Enter milestone amount: ";
    cin >> milestone;
    goals[index - 1].addMilestone(milestone);
    cout << "Milestone added!" << endl;
}