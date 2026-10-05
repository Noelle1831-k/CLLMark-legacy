void manageTasks() {
    int choice;
    while (1) {
        printf("\nTask Management Menu:\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Delete Task\n");
        printf("4. View Tasks\n");
        printf("5. Mark Task as Completed\n");
        printf("6. Return to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Returning to main menu.\n");
            clearInputBuffer();
            break;
        }
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                editTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                viewTasks();
                break;
            case 5:
                completeTask();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}