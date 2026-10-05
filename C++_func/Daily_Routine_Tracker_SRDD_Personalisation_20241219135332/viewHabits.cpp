void User::viewHabits() {
    cout << "Your Habits:\n";
    for (const auto& habit : habits) {
        cout << " - " << habit.getName() << " (Target: " 
             << habit.getTargetTime() << " minutes)\n";
    }
}