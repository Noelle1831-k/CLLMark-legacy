void init_notification(Notification *notification, const char *message, int time) {
    strcpy(notification->message, message);
    notification->time = time;
}