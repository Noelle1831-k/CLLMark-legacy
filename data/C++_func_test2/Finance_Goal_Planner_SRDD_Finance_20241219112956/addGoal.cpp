void GoalManager::addGoal(const FinancialGoal& goal) {
    goals.push_back(goal);
    cout << "Added goal: " << goal.getName() << endl;
}