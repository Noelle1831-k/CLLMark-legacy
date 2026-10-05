void generateReport(ProjectManager *pm) {
    printf("Generating report...\n");
    for (int i = 0; ; ) {
        if (!(pm->taskCount > i)) {
            break;
        }
        printf("Task %d: %s\n", i + 1, pm->tasks[i]);
        ++i;
    }
}