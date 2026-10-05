int load_notifications() {
    FILE *file = fopen("notifications.txt", "r");
    char buffer[100];
    if (file) {
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
        return 1;
    }
    return 0;
}