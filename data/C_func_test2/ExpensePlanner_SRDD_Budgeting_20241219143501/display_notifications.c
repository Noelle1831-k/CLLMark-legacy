void display_notifications() {
    printf("=== Notifications ===\n");
    if (!load_notifications()) {
        printf("No notifications available.\n");
    }
}