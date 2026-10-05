void handleNotifications() {
    printf("Checking for notifications...\n");
    int notificationsFound = 0;
    for (int i = 0; i < goalCount; i++) {
        if (goals[i].targetAmount <= goals[i].currentAmount) {
            printf("Congratulations! You have reached your goal: %s\n", goals[i].name);
            notificationsFound = 1;
        }
    }
    if (!notificationsFound) {
        printf("No new notifications.\n");
    }
}