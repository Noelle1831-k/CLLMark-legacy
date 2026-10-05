void User::displayHabits() {
    if (habits.empty()) {
        cout << "No habits to display.\n";
        return;
    }
    for (int i = 0; i < habits.size(); i++) {
        habits[i].displayHabit();
    }
}