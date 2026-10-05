void trigger_notification(const char *message) {
    printf("ALERT: %s\n", message);
    save_notification(message);
}