void view_task(Task *task) {
    printf("Task Name: %s\n", task->name);
    printf("Description: %s\n", task->description);
    printf("Deadline: %s\n", task->deadline);
    printf("Status: %d\n", task->status);
}