void User::recordProgress(string habitName, int completedTime) {
    for (auto& habit : habits) {
        if (habit.getName() == habitName) {
            habit.addProgress(completedTime);
            cout << "Progress recorded successfully!\n";
            return;
        }
    }
    cout << "Habit not found.\n";
}