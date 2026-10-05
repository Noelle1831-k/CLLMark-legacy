char *monitor_user_activity() {
    char *activity = (char *)malloc(256);
    if (!activity) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(activity, "Simulated user activity...");
    return activity;
}