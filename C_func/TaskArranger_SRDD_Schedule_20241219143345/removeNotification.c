void removeNotification(NotificationManager *manager, int index) {
    if (index >= 0 && index < manager->notificationCount) {
        for (int i = index; i < manager->notificationCount - 1; i++) {
            manager->notifications[i] = manager->notifications[i + 1];
        }
        manager->notificationCount--;
    }
}