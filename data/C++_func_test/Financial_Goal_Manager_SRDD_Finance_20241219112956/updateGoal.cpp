void User::updateGoal(string name, double amount) {
    for (size_t i = 0; i < goals.size(); i++) {
        if (goals[i].getName() == name) {
            goals[i].updateProgress(amount);
            return;
        }
    }
    cout << "Goal not found.\n";
}