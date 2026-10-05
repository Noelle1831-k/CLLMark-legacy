void manageTasks(TaskList *taskList) {
    int choice;
    while (1) {
        printf("\n=== Manage Tasks ===\n");
        printf("1. Create Task\n");
        printf("2. List Tasks\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createTask(taskList);
                break;
            case 2:
                listTasks(taskList);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}