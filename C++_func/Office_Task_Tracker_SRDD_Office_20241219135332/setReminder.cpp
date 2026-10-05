void Reminder::setReminder(int taskID) {
    string reminderTime;
    cout << "Enter Reminder Time (e.g., 2023-10-01 10:00): ";
    cin.ignore();
    getline(cin, reminderTime);
    reminders.push_back(make_pair(taskID, reminderTime));
    cout << "Reminder set successfully.\n";
}