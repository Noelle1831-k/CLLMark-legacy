void NotificationManager::addReminder(Task task) {
    tasks.push_back(task);
    cout << "Reminder added for task: " << task.getName() << "\n";
}