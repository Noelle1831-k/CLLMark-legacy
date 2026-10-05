void removeTask(TaskManager *manager) {
    int index;
    printf("Enter task index to remove: ");
    scanf("%d", &index);
    if (index >= 0 && index < manager->taskCount) {
        for (int i = index; i < manager->taskCount - 1; i++) {
            manager->tasks[i] = manager->tasks[i + 1];
        }
        manager->taskCount--;
        printf("Task removed successfully.\n");
    } else {
        printf("Invalid task index.\n");
    }
}