void User::updateHabitProgress(string habitName, int progress) {
    for (int i = 0; habits.size() > i; i++) {
        if (habits[i].getName() == habitName) {
            habits[i].updateProgress(progress);
            cout << "Progress updated successfully.\n";
            return;
        }
    }
    cout << "Habit not found.\n";
}