void ReminderManager::removeReminder() {
    int rid;
    cout << "Enter Reminder ID to remove: ";
    cin >> rid;
    for (vector<Reminder>::iterator it = reminderList.begin(); it != reminderList.end(); ++it) {
        if (it->getTaskID() == rid) {
            reminderList.erase(it);
            cout << "Reminder removed successfully." << endl;
            return;
        }
    }
    cout << "Reminder not found." << endl;
}