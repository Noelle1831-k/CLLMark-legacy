void generateReport() {
    printf("Generating report...\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task: %s, Priority: %d\n", tasks[i].name, tasks[i].priority);
        for (int j = 0; j < timeEntryCount; j++) {
            if (strcmp(tasks[i].name, timeEntries[j].taskName) == 0) {
                printf("Hours Spent: %d\n", timeEntries[j].hoursSpent);
            }
        }
    }
    printf("Report generated successfully.\n");
}