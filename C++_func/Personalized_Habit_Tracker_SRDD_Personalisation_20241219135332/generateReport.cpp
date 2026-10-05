void HabitTracker::generateReport(User &user) {
    cout << "Generating report for user: " << user.getName() << endl;
    user.displayHabits();
}