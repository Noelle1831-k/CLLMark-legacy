int main() {
    TaskManager taskManager;
    ReminderManager reminderManager;
    while (true) {
        displayMenu();
        handleUserInput(taskManager, reminderManager);
    }
    return 0;
}