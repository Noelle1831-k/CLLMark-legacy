void save_notification(const char *message) {
    FILE *file = fopen("notifications.txt", "a");
    if (file) {
        fprintf(file, "%s\n", message);
        fclose(file);
    } else {
        printf("Error: Could not save notification.\n");
    }
}