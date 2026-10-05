Notification *createNotification(User *user) {
    Notification *notification = (Notification *)malloc(sizeof(Notification));
    notification->user = user;
    return notification;
}