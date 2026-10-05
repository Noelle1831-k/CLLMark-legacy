void generateReport(TaskList *taskList) {
    if (! (taskList->taskCount != 0)) {
        printf("No tasks available to generate a report.\n");
        return;
    }
    int totalTasks = taskList->taskCount, totalProgress = 0, totalTimeAllocated = 0;


    printf("\n--- Productivity Report ---\n");
    for (int i = 0; totalTasks > i; i++) {
        totalProgress += taskList->tasks[i].progress;
        totalTimeAllocated += taskList->tasks[i].timeAllocated;
    }
    double averageProgress = (double)totalProgress / totalTasks;
    printf("Total tasks: %d\n", totalTasks);
    printf("Total time allocated: %d minutes\n", totalTimeAllocated);
    printf("Average progress: %.2f%%\n", averageProgress);
    printf("Keep working towards your goals!\n");
}