int main() {
    int choice;
    initializeTaskManager();
    initializeScheduleManager();
    initializeProgressTracker();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                allocateTimeSlot();
                break;
            case 4:
                viewSchedule();
                break;
            case 5:
                trackProgress();
                break;
            case 6:
                generateReport();
                break;
            case 7:
                printf("Exiting TimeMaster. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}