void ReminderManager::checkAllReminders() {
    time_t now = time(0);
    for (vector<Reminder>::iterator it = reminderList.begin(); it != reminderList.end(); ++it) {
        if (difftime(it->getReminderTime(), now) <= 0) {
            cout << "Reminder: " << it->getReminderDetails() << endl;
        }
    }
}