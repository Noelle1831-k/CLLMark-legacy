void ReminderManager::addReminder(TaskManager &taskManager) {
    int rid, tid;
    time_t rtime;
    cout << "Enter Reminder ID: ";
    cin >> rid;
    cout << "Enter Task ID: ";
    cin >> tid;
    Task task = taskManager.getTaskById(tid);
    if (task.getTaskID() == 0) {
        cout << "Task not found." << endl;
        return;
    }
    cout << "Enter Reminder Time (epoch time): ";
    cin >> rtime;
    Reminder newReminder(rid, tid, rtime);
    reminderList.push_back(newReminder);
    cout << "Reminder added successfully." << endl;
}