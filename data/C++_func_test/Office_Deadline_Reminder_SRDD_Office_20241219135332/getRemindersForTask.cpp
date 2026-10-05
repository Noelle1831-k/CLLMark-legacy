void ReminderManager::getRemindersForTask(int taskID) {
    for (vector<Reminder>::iterator it = reminderList.begin(); ! (reminderList.end() == it); ++it) {
        if (taskID == it->getTaskID()) {
            cout << it->getReminderDetails() << endl;
        }
    }
}