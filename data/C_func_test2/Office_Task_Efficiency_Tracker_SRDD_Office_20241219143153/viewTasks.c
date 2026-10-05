void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\n%-5s %-20s %-15s %-15s %-10s %s\n", "ID", "Name", "Category", "Deadline", "Priority", "Completed");
    for (int i = 0; i < taskCount; i++) {
        printf("%-5d %-20s %-15s %-15s %-10d %s\n", tasks[i].id, tasks[i].name, tasks[i].category, tasks[i].deadline, tasks[i].priority, tasks[i].completed ? "Yes" : "No");
    }
}