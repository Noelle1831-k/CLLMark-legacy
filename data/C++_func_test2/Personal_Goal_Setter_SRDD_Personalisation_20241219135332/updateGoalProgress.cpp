void User::updateGoalProgress(string name, double value) {
    for (size_t i = 0; i < goals.size(); ++i) {
        if (goals[i].getName() == name) {
            goals[i].updateProgress(value);
            cout << "Progress updated for goal: " << name << endl;
            return;
        }
    }
    cout << "Goal not found.\n";
}