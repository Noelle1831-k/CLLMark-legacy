void generateReport() {
    printf("\nGenerating Productivity Report:\n");
    int totalHours = 0;
    for (int i = 0; i < taskCount; i++) {
        int taskDuration = tasks[i].endHour - tasks[i].startHour;
        totalHours += taskDuration;
        printf("Task: %s, Duration: %d hours\n", tasks[i].name, taskDuration);
    }
    printf("Total Scheduled Hours: %d\n", totalHours);
    printf("Number of Tasks: %d\n", taskCount);
    if (taskCount > 0) {
        printf("Average Task Duration: %.2f hours\n", (float)totalHours / taskCount);
    }
}