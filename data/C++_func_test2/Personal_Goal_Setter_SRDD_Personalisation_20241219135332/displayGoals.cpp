void User::displayGoals() const {
    for (size_t i = 0; i < goals.size(); ++i) {
        goals[i].displayGoal();
        cout << "-------------------\n";
    }
}