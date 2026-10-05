void add_task(Schedule *schedule, Task *task) {
    Task *current = schedule->head;
    if (current == NULL) {
        schedule->head = task;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = task;
    }
}