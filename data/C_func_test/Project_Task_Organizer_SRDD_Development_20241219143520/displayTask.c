void displayTask(Task *task) {
    printf("\nTask Name: %s\n", task->name);
    printf("Description: %s\n", task->description);
    printf("Assignee: %s\n", task->assignee);
    printf("Status: %s\n", task->status);
}