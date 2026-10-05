void listNotifications(const NotificationManager *manager) {
    for (int i = 0; i < manager->notificationCount; i++) {
        printf("Task: %s, Notification Time: %s\n", manager->notifications[i].task->title, manager->notifications[i].notificationTime);
    }
}