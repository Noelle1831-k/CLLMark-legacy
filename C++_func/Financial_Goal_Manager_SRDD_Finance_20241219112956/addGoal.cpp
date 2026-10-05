void User::addGoal(string name, double target, double current, int deadline) {
    FinancialGoal goal(name, target, current, deadline);
    goals.push_back(goal);
    cout << "Goal added successfully.\n";
}