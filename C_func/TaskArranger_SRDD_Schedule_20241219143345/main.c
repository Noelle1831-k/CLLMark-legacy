int main() {
    TaskManager taskManager;
    NotificationManager notificationManager;
    UserInterface ui;
    initTaskManager(&taskManager);
    initNotificationManager(&notificationManager);
    initUserInterface(&ui, &taskManager, &notificationManager);
    runUserInterface(&ui);
    return 0;
}