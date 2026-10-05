void User::editHabit(string habitName, int newTargetTime) {
    for (auto& habit : habits) {
        if (habit.getName() == habitName) {
            habit.setTargetTime(newTargetTime);
            cout << "Habit updated successfully!\n";
            return;
        }
    }
    cout << "Habit not found.\n";
}