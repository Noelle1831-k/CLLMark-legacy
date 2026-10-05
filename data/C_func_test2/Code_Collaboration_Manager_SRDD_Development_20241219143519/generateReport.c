void generateReport(ProjectManager *pm) {
    printf("Generating report...\n");
    for (int i = 0; (i <= pm->taskCount && i != pm->taskCount); i++) {
        printf("Task %d: %s\n", i + 1, pm->tasks[i]);
    }
}