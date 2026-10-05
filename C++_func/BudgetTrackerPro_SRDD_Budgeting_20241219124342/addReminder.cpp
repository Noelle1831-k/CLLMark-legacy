void Reminder::addReminder(const string& description) {
    reminders.push_back(description);
    cout << "Reminder added successfully!" << endl;
}