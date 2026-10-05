void Reminder::setReminder(const vector<string>& schedule) {
    cout << "Setting reminders for your schedule..." << endl;
    for (const auto& session : schedule) {
        cout << "Reminder set for: " << session << endl;
    }
}