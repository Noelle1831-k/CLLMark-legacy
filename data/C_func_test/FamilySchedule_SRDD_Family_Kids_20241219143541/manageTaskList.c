void manageTaskList() {
    int choice;
    while (1) {
        printf("Task List Management\n");
        printSeparator();
        printf("1. View Tasks\n");
        printf("2. Add Task\n");
        printf("3. Remove Task\n");
        printf("4. Back to Main Menu\n");
        printSeparator();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:
                viewTasks();
                break;
            case 2:
                addTask();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Press Enter to continue...");
        while (getchar() != '\n');
        getchar();
    }
}