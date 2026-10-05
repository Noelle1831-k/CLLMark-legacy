void print_task(Task *task) {
    if (task != NULL) {
        printf("Task: %s | Priority: %d | Deadline: %s\n", task->title, task->priority, task->deadline);
    }
}