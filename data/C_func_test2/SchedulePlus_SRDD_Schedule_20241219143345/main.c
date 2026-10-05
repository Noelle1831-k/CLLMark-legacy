int main() {
    printf("Welcome to SchedulePlus!\n");
    initializeTaskManager();
    initializeTimeTracker();
    int choice;
    do {
        printf("\nMenu:\n1. Add Task\n2. Delete Task\n3. Update Task\n4. Track Time\n5. Generate Report\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); 
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                trackTime();
                break;
            case 5:
                generateReport();
                break;
            case 6:
                printf("Exiting SchedulePlus. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        pauseExecution(); 
    } while (choice != 6);
    return 0;
}