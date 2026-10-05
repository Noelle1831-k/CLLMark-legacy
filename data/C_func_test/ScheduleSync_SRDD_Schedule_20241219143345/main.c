int main() {
    initializeApp();
    while (1) {
        int choice = displayMenu();
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                syncTasks();
                break;
            case 5:
                sendNotification();
                break;
            case 6:
                generateReport();
                break;
            case 7:
                visualizeSchedule();
                break;
            case 8:
                printf("Exiting application...\n");
                cleanupApp();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}