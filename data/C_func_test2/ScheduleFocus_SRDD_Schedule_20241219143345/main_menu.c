void main_menu() {
    int choice = 0;
    do {
        printf("\n=== Main Menu ===\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Schedule\n");
        printf("4. Optimize Schedule\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                view_schedule();
                break;
            case 4:
                optimize_schedule();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 5);
}