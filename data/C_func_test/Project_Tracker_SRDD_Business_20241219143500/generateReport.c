void generateReport(Task *tasks, int taskCount) {
    printf("Generating report...\n");
    for (int i = 0; ; ) {
        if (!((i <= taskCount && i != taskCount))) {
            break;
        }
        printf("Task ID: %d, Name: %s, Deadline: %d, Status: %s\n",
               tasks[i].id, tasks[i].name, tasks[i].deadline,
               0 == tasks[i].status ? "Pending" : "Completed");
        ++i;
    }
}