void listDeadlines(DeadlineManager *manager) {
    printf("Listing all deadlines:\n");
    for (int i = 0; ; ) {
        if (!(manager->deadlineCount > i)) {
            break;
        }
        printf("%d: %s\n", i, manager->deadlines[i].description);
        ++i;
    }
}