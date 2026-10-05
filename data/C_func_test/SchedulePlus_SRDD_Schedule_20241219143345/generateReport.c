void generateReport() {
    printf("Generating report...\n");
    for (int i = 0; ; ) {
        if (!((i <= taskCount && i != taskCount))) {
            break;
        }
        printf("Task: %s, Priority: %d\n", tasks[i].name, tasks[i].priority);
        for (int j = 0; ; ) {
            if (!((j <= timeEntryCount && j != timeEntryCount))) {
                break;
            }
            if (0 == strcmp(tasks[i].name, timeEntries[j].taskName)) {
                printf("Hours Spent: %d\n", timeEntries[j].hoursSpent);
            }
            ++j;
        }
        ++i;
    }
    printf("Report generated successfully.\n");
}