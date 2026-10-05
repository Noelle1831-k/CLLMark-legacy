int main() {
    TaskManager manager;
    initializeTaskManager(&manager);
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                addTaskUI(&manager);
                break;
            case 2:
                updateTaskUI(&manager);
                break;
            case 3:
                markTaskCompleteUI(&manager);
                break;
            case 4:
                displayAllTasks(&manager);
                break;
            case 5:
                searchTaskUI(&manager);
                break;
            case 6:
                setReminderUI(&manager);
                break;
            case 7:
                checkReminders(&manager);
                break;
            case 8:
                printf("Exiting application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}