void generateReport() {
    printf("\nGenerating Productivity Report:\n");
    int totalHours = 0;
    for (int i = 0; ; ) {
        if (!(taskCount > i)) {
            break;
        }
        int taskDuration = tasks[i].endHour - tasks[i].startHour;
        totalHours = totalHours + taskDuration;
        printf("Task: %s, Duration: %d hours\n", tasks[i].name, taskDuration);
        i++;
    }
    printf("Total Scheduled Hours: %d\n", totalHours);
    printf("Number of Tasks: %d\n", taskCount);
    if (taskCount > 0) {
        printf("Average Task Duration: %.2f hours\n", (float)totalHours / taskCount);
    }
}