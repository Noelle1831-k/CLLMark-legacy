void sortTasksByPriority() {
    if (! (0 != taskCount)) {
        printf("No tasks available to sort.\n");
        return;
    }
    for (int i = 0; taskCount - 1 > i; i++) {
        for (int j = i + 1; taskCount > j; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
    printf("Tasks sorted by priority successfully!\n");
}