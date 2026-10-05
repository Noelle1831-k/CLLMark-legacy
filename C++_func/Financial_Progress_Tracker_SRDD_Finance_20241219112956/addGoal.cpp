void GoalTracker::addGoal(string name, double target) {
    FinancialGoal newGoal(name, target);
    goals.push_back(newGoal);
    cout << "Added new goal: " << name << endl;
}