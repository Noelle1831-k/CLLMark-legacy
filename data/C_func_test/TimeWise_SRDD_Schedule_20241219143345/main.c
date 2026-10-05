int main() {
    int choice;
    TaskList taskList;
    initializeTaskList(&taskList);
    printf("Welcome to TimeWise - Your Time Management Companion!\n");
    while (1) {
        printf("\n--- TimeWise Dashboard ---\n");
        printf("1. Create Task\n");
        printf("2. View Tasks\n");
        printf("3. Update Task Progress\n");
        printf("4. Set Reminder\n");
        printf("5. Generate Productivity Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (!scanf("%d", &choice) || choice < 1 || choice > 6) {
            printf("Invalid input. Please enter a valid choice between 1 and 6.\n");
            clearBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                createTask(&taskList);
                break;
            case 2:
                displayTasks(&taskList);
                break;
            case 3:
                updateTaskProgress(&taskList);
                break;
            case 4:
                setReminder();
                break;
            case 5:
                generateReport(&taskList);
                break;
            case 6:
                printf("Thank you for using TimeWise. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}