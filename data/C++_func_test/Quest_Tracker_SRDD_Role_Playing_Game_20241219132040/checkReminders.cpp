void ReminderSystem::checkReminders() {
    cout << "Current Reminders:\n";
    for (auto& reminder : reminders) {
        cout << "Quest: " << reminder.first << ", Date: " << reminder.second << endl;
    }
}