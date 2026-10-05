void removeDeadline(DeadlineManager *manager) {
    int index;
    printf("Enter deadline index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < manager->deadlineCount) {
        for (int i = index; i < manager->deadlineCount - 1; i++) {
            manager->deadlines[i] = manager->deadlines[i + 1];
        }
        manager->deadlineCount--;
        printf("Deadline removed successfully.\n");
    } else {
        printf("Invalid deadline index.\n");
    }
}