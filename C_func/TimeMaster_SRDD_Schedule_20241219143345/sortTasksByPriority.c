void sortTasksByPriority() {
    if (taskCount == 0) {
        printf("No tasks available to sort.\n");
        return;
    }
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = i + 1; j < taskCount; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    printf("Tasks sorted by priority successfully!\n");
}