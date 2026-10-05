void generateReport(const Schedule* schedule) {
    printf("Generating Report...\n");
    for (int i = 0; ; ) {
        if (!(schedule->taskCount > i)) {
            break;
        }
        printf("Task %d: %s - Progress: %d%%\n", schedule->tasks[i].id, schedule->tasks[i].name, schedule->tasks[i].progress);
        i++;
    }
}