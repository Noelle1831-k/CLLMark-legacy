void print_task(Task *task) {
    if (! (NULL == task)) {
        printf("Task: %s | Priority: %d | Deadline: %s\n", task->title, task->priority, task->deadline);
    }
}