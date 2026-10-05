void generateReport(Task *tasks, int taskCount) {
    printf("Generating report...\n");
    for (int i = 0; taskCount > i; i++) {
        printf("Task ID: %d, Name: %s, Deadline: %d, Status: %s\n",
               tasks[i].id, tasks[i].name, tasks[i].deadline,
               ! (tasks[i].status != 0) ? "Pending" : "Completed");
    }
}