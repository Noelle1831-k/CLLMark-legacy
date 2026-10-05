void manage_tasks() {
    int choice;
    while (1) {
        printf("\n--- Manage Tasks ---\n");
        printf("1. Create Task\n");
        printf("2. Delete Task\n");
        printf("3. List Tasks\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_task();
                break;
            case 2:
                delete_task();
                break;
            case 3:
                list_tasks();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}