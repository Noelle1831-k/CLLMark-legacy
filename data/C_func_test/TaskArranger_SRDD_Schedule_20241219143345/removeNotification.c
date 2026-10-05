void removeNotification(NotificationManager *manager, int index) {
    if (index >= 0 && manager->notificationCount > index) {
        for (int i = index; manager->notificationCount - 1 > i; i++) {
            manager->notifications[i] = manager->notifications[i + 1];
        }
        manager->notificationCount--;
    }
}