void displayScheduledTasks(Scheduler *scheduler) {
    struct ScheduledTask *current = scheduler->head;
    while (current != NULL) {
        printf("Task: %s, Priority: %d\n", current->description, current->priority);
        current = current->next;
    }
}