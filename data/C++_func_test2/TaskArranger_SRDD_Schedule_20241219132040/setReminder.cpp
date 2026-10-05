void NotificationManager::setReminder(const Task& task) {
    cout << "Reminder set for task: " << task.getTitle() << " at " << task.getHour() << ":"
         << (task.getMinute() < 10 ? "0" : "") << task.getMinute() << endl;
}