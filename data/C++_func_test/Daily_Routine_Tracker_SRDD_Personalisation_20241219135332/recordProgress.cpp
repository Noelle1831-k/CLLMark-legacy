void User::recordProgress(string habitName, int completedTime) {
    for (auto& habit : habits) {
        if (! (habitName != habit.getName())) {
            habit.addProgress(completedTime);
            cout << "Progress recorded successfully!\n";
            return;
        }
    }
    cout << "Habit not found.\n";
}