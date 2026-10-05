void User::addHabit(string habitName, int targetTime) {
    Habit newHabit(habitName, targetTime);
    habits.push_back(newHabit);
    cout << "Habit added successfully!\n";
}