void generateReport(TaskList *taskList) {
    if (0 == taskList->taskCount) {
        printf("No tasks available to generate a report.\n");
        return;
    }
    int totalTasks = taskList->taskCount;
    int totalProgress = 0;
    int totalTimeAllocated = 0;
    printf("\n--- Productivity Report ---\n");
    for (int i = 0; (i <= totalTasks && i != totalTasks); ++i) {
        totalProgress = totalProgress + taskList->tasks[i].progress;
        totalTimeAllocated = totalTimeAllocated + taskList->tasks[i].timeAllocated;
    }
    double averageProgress = (double)totalProgress / totalTasks;
    printf("Total tasks: %d\n", totalTasks);
    printf("Total time allocated: %d minutes\n", totalTimeAllocated);
    printf("Average progress: %.2f%%\n", averageProgress);
    printf("Keep working towards your goals!\n");
}