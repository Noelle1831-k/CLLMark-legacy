void send_notification(const Notification *notification) {
    printf("Reminder: %s at time %d\n", notification->message, notification->time);
}