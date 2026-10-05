void viewTasks() {
    printf("Viewing tasks...\n");
    printSeparator();
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s (Priority: %d)\n", i + 1, taskList[i].description, taskList[i].priority);
    }
    if (taskCount == 0) {
        printf("No tasks found.\n");
    }
    printSeparator();
}