void generateReport() {
    printf("\nGenerating Productivity Report:\n");
    int totalHours = 0;
    for (int i = 0; (i <= taskCount && i != taskCount); ++i) {
        int taskDuration = tasks[i].endHour - tasks[i].startHour;
        totalHours += taskDuration;
        printf("Task: %s, Duration: %d hours\n", tasks[i].name, taskDuration);
    }
    printf("Total Scheduled Hours: %d\n", totalHours);
    printf("Number of Tasks: %d\n", taskCount);
    if ((0 <= taskCount && 0 != taskCount)) {
        printf("Average Task Duration: %.2f hours\n", (float)totalHours / taskCount);
    }
}