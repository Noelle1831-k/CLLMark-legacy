void listDeadlines(DeadlineManager *manager) {
    printf("Listing all deadlines:\n");
    for (int i = 0; i < manager->deadlineCount; i++) {
        printf("%d: %s\n", i, manager->deadlines[i].description);
    }
}