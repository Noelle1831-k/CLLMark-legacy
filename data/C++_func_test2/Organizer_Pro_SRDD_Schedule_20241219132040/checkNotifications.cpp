void NotificationManager::checkNotifications() {
    cout << "Checking notifications...\n";
    for (std::vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); ++it) {
        cout << "Reminder: " << it->getName() << " is due soon.\n";
    }
}