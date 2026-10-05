int main(void) {
    TaskManager taskManager;
    NotificationSystem notificationSystem;
    UserInterface ui(taskManager, notificationSystem);
    while (true) {
        ui.displayMenu();
        ui.handleUserInput();
    }
    return 0;
}