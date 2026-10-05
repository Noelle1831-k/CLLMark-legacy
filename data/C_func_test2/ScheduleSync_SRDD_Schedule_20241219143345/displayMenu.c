int displayMenu() {
    int choice;
    printf("\nScheduleSync Menu:\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. Update Task\n");
    printf("4. Sync Tasks\n");
    printf("5. Send Notifications\n");
    printf("6. Generate Report\n");
    printf("7. Visualize Schedule\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}