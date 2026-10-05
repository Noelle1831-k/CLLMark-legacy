void generateReport() {
    printf("\n=== Productivity Report ===\n");
    int completedTasks = 0;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].status, "Completed") == 0) {
            completedTasks++;
        }
    }
    printf("Total Tasks: %d\n", taskCount);
    printf("Completed Tasks: %d\n", completedTasks);
    printf("Completion Rate: %.2f%%\n", (taskCount > 0) ? (completedTasks / (float)taskCount) * 100 : 0);
    printf("===========================\n");
}