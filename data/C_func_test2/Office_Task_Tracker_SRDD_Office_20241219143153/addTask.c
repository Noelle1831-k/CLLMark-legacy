void addTask(TaskManager *manager, Task task) {
    if (manager->taskCount < MAX_TASKS) {
        manager->tasks[manager->taskCount++] = task;
    } else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }
}