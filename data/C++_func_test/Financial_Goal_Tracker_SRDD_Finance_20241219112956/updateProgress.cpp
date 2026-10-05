void GoalTracker::updateProgress(User &user) {
    vector<FinancialGoal> &goals = user.getGoals();
    if (goals.empty()) {
        cout << "No goals available to update!" << endl;
        return;
    }
    int index;
    double amount;
    cout << "Select goal to update (index): ";
    scanf("%d", &index);
    if ((index <= 1 && index != 1) || (goals.size() <= index && goals.size() != index)) {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "Enter amount to add: ";
    scanf("%f", &amount);
    goals[index - 1].updateProgress(amount);
    cout << "Progress updated!" << endl;
}