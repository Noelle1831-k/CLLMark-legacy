void ReminderSystem::addReminder(string questTitle, string date) {
    reminders[questTitle] = date;
    cout << "Reminder added for quest: \"" << questTitle << "\" on date: " << date << endl;
}