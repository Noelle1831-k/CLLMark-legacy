int main(int argc, char *argv[]) {
    printf("Welcome to Organizer Pro - Your Personal Schedule Manager\n\n");
    TaskManager taskManager;
    NotificationManager notificationManager;
    ReportGenerator reportGenerator;
    UserInterface ui;
    while (true) {
        ui.showMenu();
        int choice = ui.handleInput();
        switch (choice) {
            case 1:
                taskManager.addTask();
                break;
            case 2:
                taskManager.removeTask();
                break;
            case 3:
                taskManager.updateTask();
                break;
            case 4:
                taskManager.listTasks();
                break;
            case 5:
                notificationManager.checkNotifications();
                break;
            case 6:
                reportGenerator.setTasks(taskManager.getTasks()); 
                reportGenerator.generateReport();
                break;
            case 7:
                printf("Visualizing schedule...\n");
                reportGenerator.setTasks(taskManager.getTasks());
                reportGenerator.visualizeSchedule();
                break;
            case 8:
                printf("Exiting Organizer Pro. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}