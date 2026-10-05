void Reminder::viewReminders() {
    cout << "==================== Reminders ====================" << endl;
    for (size_t i = 0; i < reminders.size(); i++) {
        cout << i + 1 << ". " << reminders[i] << endl;
    }
    cout << "==================================================" << endl;
}