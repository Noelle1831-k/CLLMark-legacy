void display_task(const Task *task) {
    printf("Title: %s\n", task->title);
    printf("Description: %s\n", task->description);
    printf("Priority: %d\n", task->priority);
    printf("Time Slot: %d\n", task->time_slot);
    printf("Progress: %d%%\n", task->progress);
}