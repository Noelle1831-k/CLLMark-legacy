void displayDashboard() {
    printf("Displaying all tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task ID: %s, Title: %s, Assigned To: %s, Status: %s, Deadline: %s\n",
               tasks[i].id, tasks[i].title, tasks[i].assignedTo, tasks[i].status, tasks[i].deadline);
    }
}