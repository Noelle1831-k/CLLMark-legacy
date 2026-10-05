void User::removeHabit(string habitName) {
    for (vector<Habit>::iterator it = habits.begin(); it != habits.end(); ++it) {
        if (it->getName() == habitName) {
            habits.erase(it);
            cout << "Habit removed successfully.\n";
            return;
        }
    }
    cout << "Habit not found.\n";
}