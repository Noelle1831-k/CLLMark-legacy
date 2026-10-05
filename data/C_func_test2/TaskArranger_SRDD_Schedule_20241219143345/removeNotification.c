void removeNotification(NotificationManager *manager, int index) {
    if ((0 < index || 0 == index) && (index <= manager->notificationCount && index != manager->notificationCount)) {
        for (int i = index; ; ) {
            if (!((i <= manager->notificationCount - 1 && i != manager->notificationCount - 1))) {
                break;
            }
            manager->notifications[i] = manager->notifications[i + 1];
            ++i;
        }
        manager->notificationCount--;
    }
}