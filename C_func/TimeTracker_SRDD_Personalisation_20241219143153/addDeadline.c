void addDeadline(DeadlineManager *manager) {
    if (manager->deadlineCount < MAX_DEADLINES) {
        printf("Enter deadline description: ");
        scanf(" %[^\n]", manager->deadlines[manager->deadlineCount].description);
        manager->deadlineCount++;
        printf("Deadline added successfully.\n");
    } else {
        printf("Deadline limit reached. Cannot add more deadlines.\n");
    }
}