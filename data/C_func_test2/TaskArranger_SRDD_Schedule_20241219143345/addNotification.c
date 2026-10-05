void addNotification(NotificationManager *manager, Task *task, const char *notificationTime) {
    if (manager->notificationCount < 100) {
        manager->notifications[manager->notificationCount].task = task;
        strncpy(manager->notifications[manager->notificationCount].notificationTime, notificationTime, sizeof(manager->notifications[manager->notificationCount].notificationTime) - 1);
        manager->notificationCount++;
    }
}