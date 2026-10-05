void Reminder::removeReminder(int index) {
    if (index > 0 && index <= reminders.size()) {
        reminders.erase(reminders.begin() + index - 1);
        cout << "Reminder removed successfully!" << endl;
    } else {
        cout << "Invalid index. Please try again." << endl;
    }
}