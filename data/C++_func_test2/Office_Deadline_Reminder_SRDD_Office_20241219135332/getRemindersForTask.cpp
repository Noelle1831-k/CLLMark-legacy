void ReminderManager::getRemindersForTask(int taskID) {
    for (vector<Reminder>::iterator it = reminderList.begin(); it != reminderList.end(); ++it) {
        if (it->getTaskID() == taskID) {
            cout << it->getReminderDetails() << endl;
        }
    }
}