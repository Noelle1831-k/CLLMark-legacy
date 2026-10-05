void Reminder::checkReminders() {
    cout << "Checking reminders...\n";
    for (size_t i = 0; i < reminders.size(); ++i) {
        cout << "Task ID: " << reminders[i].first << " - Reminder Time: " << reminders[i].second << "\n";
    }
}